#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

void dfs(const vector<list<int>>& g, vector<bool>& v, int begin) {
    if (v[begin]) return;

    v[begin] = true;

    for (int i : g[begin])
        dfs(g, v, i);
}

int main() {
    int nTests, count;
    string aux;

    cin >> nTests;
    cin.ignore();
    getline(cin, aux);

    while (nTests--) {
        getline(cin, aux);

        vector<list<int>> graph(aux[0] - 'A' + 1);

        while (getline(cin, aux)) {
            if (!aux.size()) break;

            graph[aux[0] - 'A'].push_back(aux[1] - 'A');
            graph[aux[1] - 'A'].push_back(aux[0] - 'A');
        }

        vector<bool> visited(graph.size());

        count = 0;

        for (int i = 0; i < graph.size(); i++) {
            if (visited[i]) continue;
            count++;

            dfs(graph, visited, i);
        }

        cout << count << '\n';
        if(nTests) cout << '\n';
    }
    return 0;
}