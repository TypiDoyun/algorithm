#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main(void) {
    int n;

    cin >> n;

    vector<int> arr(n);
    vector<int> dp(n);
    vector<int> list;
    stack<int> result;

    int dpMaxIndex = -1;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (list.empty()) list.push_back(arr[i]);
        if (arr[i] > list[list.size() - 1]) {
            list.push_back(arr[i]);
            dp[i] = list.size();
        }
        else {
            auto item = lower_bound(list.begin(), list.end(), arr[i]);
            *item = arr[i];
            dp[i] = item - list.begin() + 1;
        }
        if (dpMaxIndex == -1 || dp[dpMaxIndex] < dp[i]) dpMaxIndex = i;
    }

    cout << list.size() << endl;

    result.push(arr[dpMaxIndex]);

    for (int i = dpMaxIndex - 1; i >= 0; i--) {
        if (dp[dpMaxIndex] - dp[i] != 1) continue;
        if (arr[dpMaxIndex] <= arr[i]) continue;

        dpMaxIndex = i;
        result.push(arr[i]);
    }

    while (!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }
}