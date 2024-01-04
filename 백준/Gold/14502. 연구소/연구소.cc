#include <iostream>
#include <algorithm>
#include <array>
#include <deque>
#include <vector>

using namespace std;
typedef array<int, 2> Location;
typedef vector<vector<int>> Board;

int width, height;

int activateVirus(Board board) {
    deque<Location> queue;

    int safeArea = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (board[y][x] != 2) continue;
            
            board[y][x] = 0;
            queue.push_back(Location{ x, y });
        }
    }

    while (queue.size() > 0) {
        Location location = queue.front();
        queue.pop_front();

        if (location[0] < 0 || location[1] < 0) continue;
        if (location[0] >= width || location[1] >= height) continue;

        int& block = board[location[1]][location[0]];

        if (block != 0) continue;

        block = 2;

        queue.push_back(Location{ location[0] + 1, location[1] });
        queue.push_back(Location{ location[0] - 1, location[1] });
        queue.push_back(Location{ location[0], location[1] + 1 });
        queue.push_back(Location{ location[0], location[1] - 1 });
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (board[y][x] == 0) safeArea += 1;
        }
    }

    return safeArea;
}

int maxSafeArea = 0;

void createWall(Board& board, int leftWalls) {
    if (leftWalls == 0) {
        int result = activateVirus(board);

        maxSafeArea = max(maxSafeArea, result);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (board[y][x] != 0) continue;

            board[y][x] = 1;
            createWall(board, leftWalls - 1);
            board[y][x] = 0;
        }
    }
}

int main(void) {

    cin >> height >> width;

    Board board(height, vector<int>(width, 0));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cin >> board[y][x];
        }
    }

    createWall(board, 3);
    cout << maxSafeArea;
}