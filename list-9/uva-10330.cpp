#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

// the maximum number of vertices
#define NN 1024

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
    int nRegulators, nLinks, i, j, c, aux;

    while (cin >> nRegulators) {
        // Liga os Reguladores em seus auxiliares
        for (int i = 1; i <= nRegulators; i++)
            cin >> cap[i][nRegulators + i];

        cin >> nLinks;

        while (nLinks--) {
            cin >> i >> j >> c;
            // Liga os auxiliares em novos reguladores
            cap[nRegulators + i][j] += c;
        }

        // Conexões de Barisal e conexões de Dhaka
        cin >> i >> j;

        for (int k = 0; k < i + j; k++) {
            cin >> aux;
            if (k < i) cap[0][aux] = INT_MAX;
            else cap[nRegulators + aux][nRegulators * 2 + 1] = INT_MAX;
        }

        printf("%d\n", fordFulkerson(nRegulators * 2 + 2, 0, nRegulators * 2 + 1));

        for (int i = 0; i < nRegulators * 2 + 2; i++)
            for (int j = 0; j < nRegulators * 2 + 2; j++)
                cap[i][j] = 0;
    }

    return 0;
}
