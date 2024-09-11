#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef unsigned long long ULL;

int main() {
    ULL min, max;

    cin >> min >> max;

    ULL i = 2;

    int ans = max - min + 1;

    vector<bool> list(max - min + 1);

    ULL limit = sqrt(max);

    for (ULL sqrRoot = 2; sqrRoot <= limit; sqrRoot++) {
        ULL sqr = sqrRoot * sqrRoot;

        int start, end;

        start = min / sqr;
        end = max / sqr;

        if (min % sqr != 0) start++;

        for (ULL i = start; i <= end; i++) {
            int num = i * sqr - min;

            if (list[num]) continue;

            list[num] = true;
            ans--;
        }
    }

    cout << ans;
}