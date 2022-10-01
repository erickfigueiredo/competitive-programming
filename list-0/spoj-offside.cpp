// Aluno: Erick Figueiredo
// Problema: he is offside!

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, d;

    while (true) {
        cin >> a >> d;

        if (!(a || d)) break;

        int attack[a], defense[d];

        for (int i = 0; i < a; i++)
            cin >> attack[i];

        for (int i = 0; i < d; i++)
            cin >> defense[i];

        sort(attack, attack + a, less<int>());
        sort(defense, defense + d, less<int>());

        (d < 2 || attack[0] < defense[1]) ? cout << "Y\n" : cout << "N\n";
    }

    return 0;
}
