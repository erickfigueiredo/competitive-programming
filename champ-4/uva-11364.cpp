#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int tests, n;

    cin >> tests;

    while (tests--) {
        cin >> n;
        vector<int>store(n);

        for (int i = 0; i < n; i++)
            cin >> store[i];

        sort(store.begin(), store.end());

        cout << 2 * (store[n - 1] - store[0]) << '\n';
    }
    return 0;
}
