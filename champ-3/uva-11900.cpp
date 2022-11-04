#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test, n, p, q, aux, ovos;
    cin >> test;

    for (int j = 0; j < test; j++)
    {
        ovos = 0;
        cin >> n >> p >> q;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v.push_back(aux);
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++)
        {
            if (p > 0 && q > 0)
            {
                if (q >= v[i])
                {
                    ovos++;
                    q -= v[i];
                    p--;
                }
            }
            else
                break;
        }

        printf("Case %d: %d\n", j + 1, ovos);
    }
    return 0;
}