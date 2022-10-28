#include <iostream>
using namespace std;

int main() {
    long long n, l, u, mask, pow, aux;

    while (cin >> n >> l >> u) {
        mask = 0;

        for (int i = 31; i >= 0; i--) {
            pow = 1ll << i;
            aux = mask | pow;

            if (n & pow) {
                // Underflow
                if (aux <= l) mask |= pow;
            }
            // Overflow
            else if (aux <= u) mask |= pow;
        }

        cout << mask << endl;
    }
    return 0;
}