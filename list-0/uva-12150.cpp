// Aluno: Erick Figueiredo
// Problema: Pole Position

#include <iostream>

using namespace std;

int main() {
    int nCars, car, pChange;
    bool possible = true;

    while (true) {
        cin >> nCars;
        if (!nCars) break;

        int startPositions[nCars] = { 0 };

        for (int i = 0; i < nCars; i++) {
            cin >> car >> pChange;

            if (possible) {
                if (i + pChange < 0 || i + pChange > nCars - 1 || startPositions[i + pChange]) {
                    possible = false;
                }
                else {
                    startPositions[i + pChange] = car;
                }
            }
        }

        if (possible) {
            for (int i = 0; i < nCars; i++)
                (i == nCars - 1) ? cout << startPositions[i] << '\n' : cout << startPositions[i] << ' ';
        }
        else {
            cout << "-1\n";
        }

        possible = true;
    }

    return 0;
}
