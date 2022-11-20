#include <iostream>
#include <vector>
using namespace std;

int main() {
    int cents;
    int coins[5] = { 1, 5, 10, 25, 50 };

    vector<vector<int>>waysToChange(6, vector<int>(7490, -1));

    // If doesn't have any coin there is always just ONE way to make changes.
    for (int i = 0; i < 6; i++)waysToChange[i][0] = 1;
    // If doesn't have any coins to change there is ways ZERO ways to change.
    for (int i = 1; i < 7490; i++)waysToChange[0][i] = 0;

    while (cin >> cents) {

        for (int i = 1; i < 6; i++)
            for (int j = 1; j < cents + 1; j++) {
                if (waysToChange[i][j] != -1) continue;
                waysToChange[i][j] = waysToChange[i - 1][j] + (j-coins[i-1] >=0 ? waysToChange[i][j - coins[i - 1]] : 0);
            }
            
        cout << waysToChange[5][cents] << '\n';
    }

    return 0;
}
