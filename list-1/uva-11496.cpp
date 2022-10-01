#include <iostream>
using namespace std;

int main() {
    int n, nPeaks;

    while (true) {
        nPeaks = 0;

        cin >> n;
        if (!n) break;

        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int i = 0; i < n; i++) {
            if (!i) {
                if ((arr[i + 1] < arr[i] && arr[i] > arr[n - 1]) || (arr[i + 1] > arr[i] && arr[i] < arr[n - 1]))
                    nPeaks++;
            }
            else if (i == n - 1) {
                if ((arr[i - 1] < arr[i] && arr[i] > arr[0]) || (arr[i - 1] > arr[i] && arr[i] < arr[0]))
                    nPeaks++;
            }
            else if ((arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) || (arr[i - 1] > arr[i] && arr[i] < arr[i + 1]))
                nPeaks++;
        }

        cout << nPeaks << endl;
    }
    return 0;
}
