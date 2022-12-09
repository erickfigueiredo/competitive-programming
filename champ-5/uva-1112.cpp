#include <bits/stdc++.h>

using namespace std;
#define INF 987654321

void solve()
{
    int nSalas, saida, tempo, nArestas;
    cin >> nSalas >> saida >> tempo >> nArestas;
    int aux, aux1, custo;
    vector<vector<int>> m(nSalas, vector<int>(nSalas, INF));

    for (int i = 0; i < nArestas; i++)
    {
        cin >> aux >> aux1 >> custo;

        m[aux - 1][aux1 - 1] = custo;
    }
    for (int i = 0; i < nSalas; i++)

        m[i][i] = 0;

    for (int k = 0; k < nSalas; k++)
    {
        for (int i = 0; i < nSalas; i++)
            for (int j = 0; j < nSalas; j++)
            {
                if (m[i][k] != INF && m[k][j] != INF && m[i][j] > m[i][k] + m[k][j])
                    m[i][j] = m[i][k] + m[k][j];
            }
    }

    int cont = 0;
    for (int i = 0; i < nSalas; i++)
    {
        if (m[i][saida - 1] <= tempo)
            cont++;
    }
    cout << cont << "\n";
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        solve();
        if (n != 0)
            cout << "\n";
    }
}