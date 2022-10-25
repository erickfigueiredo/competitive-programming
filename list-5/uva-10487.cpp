#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q, count = 1, best, curr, aux;

    while (cin >> n) {
        if (!n) break;

        printf("Case %d:\n", count++);

        vector<int> elements(n);
        for (int i = 0; i < n; i++)
            cin >> elements[i];

        cin >> q;
        while (q--) {
            cin >> aux;
            best = elements[0] + elements[1];

            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++) {
                    curr = elements[i] + elements[j];

                    if (abs(best - aux) > abs(curr - aux)) best = curr;
                }

            printf("Closest sum to %d is %d.\n", aux, best);
        }
    }
    return 0;
}