#include <iostream>

using namespace std;

int arr[1000] = { 0 };

int main() {
    int numberOfSubjects;

    cin >> numberOfSubjects;

    double sum = 0;
    int maxScore = 0;

    for (int i = 0; i < numberOfSubjects; i++) {
        int score;
        cin >> score;

        if (maxScore < score) {
            maxScore = score;
        }
        arr[i] = score;
    }

    for (int i = 0; i < numberOfSubjects; i++) {
        sum += (double)arr[i] / maxScore * 100;
    }

    cout << sum / numberOfSubjects;
}