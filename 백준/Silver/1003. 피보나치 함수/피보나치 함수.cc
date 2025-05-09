#include <iostream>

using namespace std;

int one[41] = { 0, 1 };
int zero[41] = { 1, 0 };

int main() {
    int repeat;
    
    cin >> repeat;
    
    for (int i = 2; i < 41; i++) {
        one[i] = one[i - 1] + one[i - 2];
        zero[i] = zero[i - 1] + zero[i - 2];
    }
    
    while (repeat--) {
        int n;
        
        cin >> n;
        
        printf("%d %d\n", zero[n], one[n]);
    }
}