#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, aux;

    while (cin >> n) {
        vector<vector<int>> graph(n, vector<int>(n));
        vector<int> vertexToDelete(n);
        vector<long long> acc(n);
        vector<bool> deleted(n);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> graph[i][j];

        for (int i = n-1; i >= 0; i--) {
            cin >> vertexToDelete[i];
            vertexToDelete[i]--;
        }

        for (int k = 0; k < n; k++) {
            aux = vertexToDelete[k];
            deleted[aux] = true;

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    graph[i][j] = min(graph[i][j], graph[i][aux] + graph[aux][j]);
                    if (deleted[i] && deleted[j]) 
                        acc[k] += graph[i][j];
                }
        }

        for (int i = n-1;i >= 0; i--)
            i > 0 ? cout << acc[i] << ' ' : cout << acc[i];

        cout << '\n';
    }
    return 0;
}