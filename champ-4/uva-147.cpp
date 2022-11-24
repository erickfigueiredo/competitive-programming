#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


int main() {
    int cents;
    double aux;
    int coins[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };

    vector<vector<unsigned long long>>waysToChange(12, vector<unsigned long long>(30001, -1));

    for (int i = 0; i < 12; i++)waysToChange[i][0] = 1;
    for (int i = 1; i < 30001; i++)waysToChange[0][i] = 0;

    while (cin >> aux) {
        if(aux <= 1e-9) break;
        cents = (aux * 100.) + 1e-3;


        for (int i = 1; i < 12; i++)
            for (int j = 1; j < cents + 1; j++) {
                if (waysToChange[i][j] != -1) continue;
                waysToChange[i][j] = waysToChange[i - 1][j] + (j - coins[i - 1] >= 0 ? waysToChange[i][j - coins[i - 1]] : 0);
            }

        cout << fixed << setprecision(2) << setw(6) << aux << setw(17) << waysToChange[11][cents] << '\n';
    }

    return 0;
}
