#include <iostream>
#include <cmath>

using namespace std;

bool mengerSponge(int x, int y, int n, int k, int s) {
    if (s <= 0) return 0;

    int nextSize = pow(n, s - 1);
    int size = nextSize * n;
    int empty = size / n * k;

    int left = (size - empty) / 2;

    if (left <= x && size - left > x && left <= y && size - left > y) return true;
    else return mengerSponge(x % nextSize, y % nextSize, n, k, s - 1);
}

int main() {
    int s, n, k, r1, r2, c1, c2;
    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
    for (int y = r1; y <= r2; y++) {
        for (int x = c1; x <= c2; x++) {
            bool result = mengerSponge(x, y, n, k, s);
            cout << result;
        }
        cout << endl;
    }
}