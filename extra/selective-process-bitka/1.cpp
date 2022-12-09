#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int totalItems, nComprados, nGratis, total;

    while (cin >> totalItems) {
        total = 0;
        
        vector<int> items(totalItems);
        for (int i = 0; i < totalItems; i++)
            cin >> items[i];

        cin >> nComprados >> nGratis;

        sort(items.begin(), items.end(), [](int i1, int i2) {
            return i1 > i2;
            });

        for (int i = nComprados - nGratis; i < nComprados; i++)
            total += items[i];


        cout << "Resultado: " << total << "\n\n";
    }
    return 0;
}