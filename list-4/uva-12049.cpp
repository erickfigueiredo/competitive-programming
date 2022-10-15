#include <iostream>
#include <list>

using namespace std;

int main() {
    int tests, lA, lB, aux, count;
    cin >> tests;

    while (tests--) {
        count = 0;
        cin >> lA >> lB;
        list<int> l1, l2;

        for (int i = 0; i < lA; i++) {
            cin >> aux;
            l1.push_back(aux);
        }

        for (int i = 0; i < lB; i++) {
            cin >> aux;
            l2.push_back(aux);
        }

        l1.sort();
        l2.sort();

        list<int>::iterator it1 = l1.begin(), it2 = l2.begin();
        while ((it1 != l1.end()) && (it2 != l2.end())) {
            if (*it1 == *it2) {
                count++;
                it1++;
                it2++;
            }
            else if (*it1 < *it2) it1++;
            else it2++;
        }

        cout << (lA + lB) - 2 * count << '\n';
    }
    return 0;
}

