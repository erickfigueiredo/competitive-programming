#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, aux, maxSum, row, col;
    bool initialized;

    while (cin >> n >> m) {

        vector<vector<int>> tabuleiro(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> tabuleiro[i][j];

        initialized = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                aux = 0;

                row = 0;
                col = j - i;

                while (row != n) {
                    if (col >= 0 && col < m)
                        aux += tabuleiro[row][col];

                    row++;
                    col++;
                }

                row = 0;
                col = j + i;
                while (row != n) {
                    if (col >= 0 && col < m) {
                        aux += tabuleiro[row][col];
                    }

                    row++;
                    col--;
                }

                aux -= tabuleiro[i][j];

                if (!initialized) {
                    maxSum = aux;
                    initialized = true;
                }
                else maxSum = max(aux, maxSum);
            }
        }

        cout << "Resultado: " << maxSum << "\n\n";
    }
    return 0;
}