#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
    int n, maxi;

    while (cin >> n) {
        vector<vector<int>> matrix(n, vector<int>(n)), sums(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                sums[i][j] = matrix[i - 1][j - 1] + sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];

        maxi = INT_MIN;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 0; k < i; k++)
                    for (int l = 0; l < j; l++)
                        maxi = max(maxi, sums[i][j] - sums[i][l] - sums[k][j] + sums[k][l]);

        cout << maxi << '\n';
    }

    return 0;
}