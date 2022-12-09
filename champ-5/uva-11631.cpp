#include <bits/stdc++.h>
using namespace std;

int n, m;

class UnionFind
{
private:
    vector<int> representante;

public:
    void createSet(int tam)
    {
        representante.resize(tam);
        for (int i = 0; i < tam; i++)
            representante[i] = i;
    }
    int findSet(int elemento)
    {
        if (representante[elemento] == elemento)
        {
            return elemento;
        }
        representante[elemento] = findSet(representante[elemento]);
        return representante[elemento];
    }
    void mergeSets(int i, int j)
    {
        representante[findSet(i)] = findSet(j);
    }
    bool isSameSet(int i, int j)
    {
        return (findSet(i) == findSet(j));
    }
};

struct Edge
{
    int i, j;
    double distancia;
    Edge(int _i, int _j, double _distancia) : i(_i), j(_j), distancia(_distancia) {}

    bool operator<(const Edge &other)
    {
        return distancia < other.distancia;
    }
};

int aux, aux1, custo;
void solve()
{

    vector<Edge> distancias;
    int total = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> aux >> aux1 >> custo;

        distancias.push_back(Edge(aux, aux1, custo));
        distancias.push_back(Edge(aux1, aux, custo));

        total += custo;
    }

    sort(distancias.begin(), distancias.end());
    UnionFind un;
    un.createSet(n);
    long long int caminho = 0;
    for (auto i : distancias)
    {
        //se nao forma ciclo, adicione ao resultado
        if (!un.isSameSet(i.i, i.j))
        {
            caminho += i.distancia;
            un.mergeSets(i.i, i.j);
        }
    }
    cout << abs(total - caminho) << "\n";
}

int main()
{
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        solve();
    }
}
