#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    int n;

    cin >> n;

    while (n--) {
        regex re("^(100+1+|01)+$");
        string signal;

        cin >> signal;

        bool result = regex_search(signal, re);

        if (result) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}