#include <iostream>
#include <cstring>
using namespace std;

// the maximum number of vertices
#define NN 1024
#define INF 987654321 

// adjacency matrix (fill this up)
int cap[NN][NN]{ 0 };

// flow network
int fnet[NN][NN];

// BFS
int q[NN], qf, qb, previous[NN];

int fordFulkerson(int n, int s, int t) {
    // init the flow network
    memset(fnet, 0, sizeof(fnet));

    int flow = 0;

    while (true) {
        // find an augmenting path
        memset(previous, -1, sizeof(previous));
        qf = qb = 0;
        previous[q[qb++] = s] = -2;
        while (qb > qf && previous[t] == -1)
            for (int u = q[qf++], v = 0; v < n; v++)
                if (previous[v] == -1 && fnet[u][v] - fnet[v][u] < cap[u][v])
                    previous[q[qb++] = v] = u;

        // see if we're done
        if (previous[t] == -1) break;

        // get the bottleneck capacity
        int bot = 0x7FFFFFFF;
        for (int v = t, u = previous[v]; u >= 0; v = u, u = previous[v])
            bot = min(cap[u][v] - fnet[u][v] + fnet[v][u], bot);

        // update the flow network
        for (int v = t, u = previous[v]; u >= 0; v = u, u = previous[v])
            fnet[u][v] += bot;

        flow += bot;
    }

    return flow;
}

int main() {
    int machines, wires, m, m1, c;

    while (cin >> machines >> wires) {
        if(!machines && !wires) break;

        cap[0][machines] = INF;
        cap[machines - 1][2 * machines - 1] = INF;

        for (int i = 0; i < machines - 2; i++) {
            cin >> m >> c;
            cap[m - 1][m - 1 + machines] = c;
        }

        while (wires--) {
            cin >> m >> m1 >> c;
            m--; m1--;

            cap[m + machines][m1] = c;
            cap[m1 + machines][m] = c;
        }

        printf("%d\n", fordFulkerson(machines * 2, 0, 2 * machines - 1));
        memset(cap, 0, sizeof(cap));
    }

    return 0;
}