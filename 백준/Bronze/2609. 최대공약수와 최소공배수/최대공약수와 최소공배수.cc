#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int a, b;
    
    cin >> a >> b;
    
    int gcdAB = gcd(a, b);
    
    cout << gcd(a, b) << endl;
    cout << a * b / gcdAB;
}