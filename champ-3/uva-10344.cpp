#include <bits/stdc++.h>
using namespace std;

bool dfs(int v[], int idx, int total)
{
    if (idx == 5)
    {
        // cout << total << endl;
        return total == 23;
    }
    return dfs(v, idx + 1, total + v[idx]) || dfs(v, idx + 1, total - v[idx]) || dfs(v, idx + 1, total * v[idx]);
}
int main()
{
    bool exit;
    int v[5];
    while (true)
    {
        exit = true;
        for (int i = 0; i < 5; i++)
        {
            cin >> v[i];
            if (v[i])
                exit = false;
        }

        if (exit)
            break;
        sort(v, v + 5);
        bool aux;
        do
        {
            aux = dfs(v, 1, v[0]);
            if (aux)
                break;
        } while (next_permutation(v, v + 5));
        aux ? cout << "Possible\n" : cout << "Impossible\n";
    }
    return 0;
} // namespace std;
