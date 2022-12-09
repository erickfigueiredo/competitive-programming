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
    int nBuilds, preConn, n1, n2, conn;
    double totalCost;

    while (cin >> nBuilds) {
        vector<pair<int, int>> buildings(nBuilds);

        for (int i = 0; i < nBuilds; i++)
            cin >> buildings[i].first >> buildings[i].second;

        UnionFind uf(nBuilds);


        cin >> preConn;
        conn = 0;
        for (int i = 0; i < preConn; i++) {
            cin >> n1 >> n2;
            n1--; n2--;
            if (uf.findSet(n1) != uf.findSet(n2)) {
                uf.mergeSets(n1, n2);
                conn++;
            }
        }


        vector<Edge> edges;
        for (int i = 0; i < nBuilds; i++)
            for (int j = i + 1; j < nBuilds; j++)
                if (uf.findSet(i) != uf.findSet(j))
                    edges.push_back(calcCost(i, j, buildings[i], buildings[j]));


        sort(edges.begin(), edges.end());

        totalCost = 0;

        for (int i = 0; i < edges.size(); i++) {
            int compU = uf.findSet(edges[i].v);
            int compV = uf.findSet(edges[i].w);

            if (compU != compV) {
                totalCost += edges[i].cost;
                uf.mergeSets(edges[i].v, edges[i].w);
                conn++;

                if (conn == nBuilds - 1) break;
            }
        }

        cout << fixed << setprecision(2) << totalCost << '\n';
    }

    return 0;
}