#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool bp(const vector<list<int>> &g, vector<bool> &visited, vector<int> &color, int begin) {
    visited[begin] = true;

    for(int i : g[begin]) {
        if(color[begin] == color[i]) return false;
        if(visited[i]) continue;

        if(color[begin] == 1) color[i] = 2;
        else color[i] = 1;

        if(!bp(g, visited, color, i)) return false;
    }

    return true;
}


bool dfs(const vector<list<int>> &g) {
    vector<bool> visited(g.size());
    vector<int> color(g.size());

    for(int i = 0; i < g.size(); i++) {
        if(visited[i]) continue;

        color[i] = 1;
        if(!bp(g, visited, color, i)) return false;
    }

    return true;
}

int main() {
    int v, e, v1, v2;

    while(cin >> v, v) {
        vector<list<int>> graph (v);

        cin >> e;

        for(int i = 0; i < e; i++) {
            cin >> v1 >> v2;

            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }

        dfs(graph) ? cout << "BICOLORABLE.\n" : cout << "NOT BICOLORABLE.\n";
    }

    return 0;
}
