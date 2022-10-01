#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    float acc, mean, upBound, lowBound, exchUp, exchLow;

    while (true) {
        acc = 0;
        exchUp = exchLow = 0;
        cin >> n;
        if (!n) break;

        float values[n];
        for (int i = 0; i < n; i++) {
            cin >> values[i];
            acc += values[i];
        }
        mean = (acc / n);
        upBound = ceil(mean * 100) / 100;
        lowBound = floor(mean * 100) / 100;

        for (int i = 0; i < n; i++) {
            if (values[i] > upBound) {
                exchUp += values[i] - upBound;
            }

            if (values[i] < lowBound) {
                exchLow += lowBound - values[i];
            }
        }

        printf("$%.2f\n", max(exchLow, exchUp));
    }
    return 0;
}

