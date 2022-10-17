#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    long long m, f;
    long double bC, aC;

    for (int i = 1; cin >> m >> f; i++) {
        if (!m && !f) break;

        printf("Case %d: :-", i);
        if (!m || m == 1) {
            cout << "\\\n";
            continue;
        }

        bC = min( (long double)f / m, (long double)1.0);

        f--; m--;
        aC = min((long double)f/ m, (long double)1.0);

        if (aC > bC)
            cout << ")\n";
        else if (bC > aC)
            cout << "(\n";
        else
            cout << "|\n";

    }
    return 0;
}
