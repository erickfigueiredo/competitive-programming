#include <map>
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int nTests, total;
    string specie;

    cin >> nTests;
    cin.ignore();
    getline(cin, specie);

    while (nTests--) {
        total = 0;
        map<string, int> species;
        while (getline(cin, specie)) {
            if (specie.empty()) break;
            total++;
            species[specie]++;
        }

        for (const auto& kv : species)
            cout << fixed << setprecision(4) << kv.first << ' ' << round((((double)kv.second / total) * 100) * 1e4) / 1e4 << '\n';

        if(nTests)cout << '\n';
    }
    return 0;
}
