#include <iostream>
#include <queue>

using namespace std;

#define HEIGHT 1500
#define WIDTH 1500

short map[HEIGHT][WIDTH];
bool visited[HEIGHT][WIDTH];
// 0: water
// 1: ice

bool isValid(int x, int y, int w, int h) {
    return !(x < 0 || x >= w || y < 0 || y >= h);
}

bool breakIce(int x, int y, int w, int h) {
    if (!isValid(x, y, w, h)) {
        return false;
    }
    if (map[y][x] == 0) {
        return false;
    }
    map[y][x] = 0;

    return true;
}

int main(void) {
    queue<pair<int, int>> water;
    queue<pair<int, int>> waterTemp;
    queue<pair<int, int>> swan;
    queue<pair<int, int>> swanTemp;
    pair<int, int> l1, l2;
    bool finish = false;
    int row, column;
    int day = 0;
    bool l = false;

    cin >> row >> column;

    for (int y = 0; y < row; y++) {
        for (int x = 0; x < column; x++) {
            char code;

            cin >> code;

            if (code == '.') {
                map[y][x] = 0;
                water.push(make_pair(x, y));
            }
            else if (code == 'X') map[y][x] = 1;
            else if (code == 'L') {
                pair<int, int> p = make_pair(x, y);
                water.push(p);
                if (!l) l1 = p;
                else l2 = p;
                l = true;
            }
        }
    }
    swan.push(l1);

    while (true) {
        while (swanTemp.size() > 0) {
            swan.push(swanTemp.front());
            swanTemp.pop();
        }
        
        while (swan.size() > 0) {
            auto coord = swan.front();
            swan.pop();


            if (!isValid(coord.first, coord.second, column, row)) continue;
            if (visited[coord.second][coord.first]) continue;
            if (coord.first == l2.first && coord.second == l2.second) finish = true;
            if (finish) break;
            if (map[coord.second][coord.first] == 1) {
                swanTemp.push(make_pair(coord.first, coord.second));
            }
            else {
                visited[coord.second][coord.first] = true;
                swan.push(make_pair(coord.first + 1, coord.second));
                swan.push(make_pair(coord.first - 1, coord.second));
                swan.push(make_pair(coord.first, coord.second + 1));
                swan.push(make_pair(coord.first, coord.second - 1));
            }
        }


        if (finish) break;

        day++;

        while (waterTemp.size() > 0) {
            water.push(waterTemp.front());
            waterTemp.pop();
        }

        while (water.size() > 0) {
            auto coord = water.front();
            water.pop();

            if (breakIce(coord.first + 1, coord.second, column, row)) {
                waterTemp.push(make_pair(coord.first + 1, coord.second));
            }
            if (breakIce(coord.first - 1, coord.second, column, row)) {
                waterTemp.push(make_pair(coord.first - 1, coord.second));
            }
            if (breakIce(coord.first, coord.second + 1, column, row)) {
                waterTemp.push(make_pair(coord.first, coord.second + 1));
            }
            if (breakIce(coord.first, coord.second - 1, column, row)) {
                waterTemp.push(make_pair(coord.first, coord.second - 1));
            }
        }
    }

    std::cout << day;

}