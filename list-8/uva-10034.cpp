#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

class UnionFind {
public:
    UnionFind(int size) {
        parent.resize(size);

        for (int i = 0; i < size; i++)
            parent[i] = i;
    }

    int findSet(int el) {
        if (parent[el] == el)
            return el;

        parent[el] = findSet(parent[el]);
        return parent[el];
    }

    void mergeSets(int i, int j) {
        parent[findSet(i)] = findSet(j);
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

private:
    vector<int>parent;
};

struct Edge {
    int v, w;
    double cost;

    Edge(int v = -1, int w = -1, double cost = 0) : v(v), w(w), cost(cost) {}

    bool operator < (const Edge& other) {
        return this->cost < other.cost;
    }
};

Edge calcCost(int i, int j, const pair<double, double>& pI, const pair<double, double>& pJ) {
    double dist = sqrt(pow(pI.first - pJ.first, 2) + pow(pI.second - pJ.second, 2));

    return Edge(i, j, dist);
}

int main() {
    int nTests, nVertex, nConn;
    double x, y, totalCost;

    cin >> nTests;

    while (nTests--) {
        cin >> nVertex;

        vector<pair<double, double>> points(nVertex);

        for (int i = 0; i < nVertex; i++) {
            cin >> x >> y;

            points[i] = { x, y };
        }

        vector<Edge> edges;
        for (int i = 0; i < nVertex; i++)
            for (int j = i + 1; j < nVertex; j++)
                edges.push_back(calcCost(i, j, points[i], points[j]));

        sort(edges.begin(), edges.end());
        UnionFind uf(nVertex);

        nConn = 0;
        totalCost = 0;

        for (int i = 0; i < edges.size(); i++) {
            int compU = uf.findSet(edges[i].v);
            int compV = uf.findSet(edges[i].w);

            if (compU != compV) {
                totalCost += edges[i].cost;
                uf.mergeSets(edges[i].v, edges[i].w);
                nConn++;

                if (nConn == nVertex - 1) break;
            }
        }

        cout << fixed << setprecision(2) << totalCost << '\n';
        if (nTests) cout << '\n';
    }
    return 0;
}