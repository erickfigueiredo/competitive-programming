#include <iostream>
#include <climits>
#include <string>
#include <vector>
using namespace std;

typedef vector<vector<int>> grid;

int calcDP(const grid& area, grid& path, int i, int j) {
    if (path[i][j] == -1) {
        path[i][j] = 1;

        if (area[i][j] > area[i + 1][j])
            path[i][j] = max(path[i][j], 1 + calcDP(area, path, i + 1, j));

        if (area[i][j] > area[i - 1][j])
            path[i][j] = max(path[i][j], 1 + calcDP(area, path, i - 1, j));

        if (area[i][j] > area[i][j + 1])
            path[i][j] = max(path[i][j], 1 + calcDP(area, path, i, j + 1));

        if (area[i][j] > area[i][j - 1])
            path[i][j] = max(path[i][j], 1 + calcDP(area, path, i, j - 1));
    }

    return path[i][j];
}

int main() {
    int nTests, n, m, maxi;
    string name;
    cin >> nTests;

    while (nTests--) {
        cin >> name >> n >> m;
        grid area(n + 2, vector<int>(m + 2, INT_MAX)), path(n + 2, vector<int>(m + 2, -2));

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                cin >> area[i][j];
                path[i][j] = -1;
            }

        maxi = -1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                maxi = max(maxi, calcDP(area, path, i, j));

        cout << name << ": " << maxi << '\n';
    }
}