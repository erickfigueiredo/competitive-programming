#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Begin: Dinic Algorithm Implementation
struct Edge {
    int v, rev;
    int cap, flow = 0;
    Edge(int v, int rev, int cap) : v(v), rev(rev), cap(cap) {}
};

class Dinic {
private:
    const int flow_inf = 987654321;
    vector<Edge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

public:
    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int rev, int cap) {
        edges.emplace_back(v, rev, cap);
        edges.emplace_back(rev, v, 0);
        adj[v].push_back(m);
        adj[rev].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].rev] != -1)
                    continue;
                level[edges[id].rev] = level[v] + 1;
                q.push(edges[id].rev);
            }
        }
        return level[t] != -1;
    }

    int dfs(int v, int pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int rev = edges[id].rev;
            if (level[v] + 1 != level[rev] || edges[id].cap - edges[id].flow < 1)
                continue;
            int tr = dfs(rev, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    int flow() {
        int f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

// End

int main() {
    int nTests, n, m, qtt, stickerID;

    cin >> nTests;

    for (int i = 0; i < nTests; i++) {
        cin >> n >> m;

        vector<vector<int>>stickers(n + m, vector<int>(n + m));

        Dinic changeRel(n + m + 2, 0, n + m + 1);

        for (int j = 1; j <= n; j++) {
            cin >> qtt;
            for (int k = 0; k < qtt; k++) {
                cin >> stickerID;
                stickers[j][stickerID]++;
            }
        }
        
        for (int j = 1; j <= m; j++) {
            changeRel.add_edge(0, j, stickers[1][j]);
            changeRel.add_edge(j, n + m + 1, 1);
        }

        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                if (!stickers[k][j])
                    changeRel.add_edge(j, m + k, 1);

                else if (stickers[k][j] > 1)
                    changeRel.add_edge(m + k, j, stickers[k][j] - 1);
            }
        }

        printf("Case #%d: %d\n", i + 1, changeRel.flow());
    }
}