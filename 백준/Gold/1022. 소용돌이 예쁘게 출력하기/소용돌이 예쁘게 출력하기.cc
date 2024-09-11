#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int f(int x, int y) {
    int n = max(abs(x), abs(y));
    int val = (2 * n + 1);
    val *= val;
 
    int diff = 2 * n;
    if (x == n)return val - (n - y);
    val -= diff;
    if (y == -n)return val - (n - x);
    val -= diff;
    if (x == -n)return val - (y + n);
    val -= diff;
    return val - (x + n);
}

int length(int i) {
    return (int)log10(i) + 1;
}

int main() {
    int r1, r2, c1, c2;

    cin >> r1 >> c1 >> r2 >> c2;

    int maxLength = -1;

    for (int y = r1; y <= r2; y++) {
        for (int x = c1; x <= c2; x++) {
            maxLength = max(maxLength, length(f(y, x)));
        }
    }

    for (int y = r1; y <= r2; y++) {
        for (int x = c1; x <= c2; x++) {
            printf("%*d ", maxLength, f(y, x));
        }
        cout << endl;
    }
}