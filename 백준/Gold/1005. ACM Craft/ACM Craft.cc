#include <iostream>
#include <vector>

using namespace std;

struct Building {
    int index;
    int time;
    vector<Building*> rules;
};

vector<Building> buildings;
vector<int> cache;

int dfs(int buildingIndex) {
    Building& building = buildings[buildingIndex];

    if (building.rules.empty()) {
        return building.time;
    }

    int maxTime = 0;
    for (Building* rule : building.rules) {
        if (cache[rule->index] == -1) {
            cache[rule->index] = dfs(rule->index);
        }
        maxTime = max(maxTime, cache[rule->index]);
    }

    return building.time + maxTime;
}

int main() {
    int numberOfGames;

    cin >> numberOfGames;

    for (int _ = 0; _ < numberOfGames; _++) {
        int numberOfBuildings, numberOfRules;

        buildings.clear();
        cache.clear();
        cin >> numberOfBuildings >> numberOfRules;

        cache.resize(numberOfBuildings, -1);

        for (int i = 0; i < numberOfBuildings; i++) {
            int time;
            cin >> time;

            buildings.push_back(Building{ i, time });
        }

        for (int i = 0; i < numberOfRules; i++) {
            int x, y;
            cin >> x >> y;

            x--;
            y--;

            buildings[y].rules.push_back(&buildings[x]);
        }

        int targetBuilding;
        cin >> targetBuilding;
        targetBuilding--;

        cout << dfs(targetBuilding) << endl;
    }
}