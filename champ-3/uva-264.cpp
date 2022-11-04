#include <bits/stdc++.h>
using namespace std;

pair<int, int> solve(int n)
{
    int i = 1, j = 1;
    int cont = 1;
    while (cont < n)
    {
        if (j == 1)
        {
            if (i % 2 == 0)
            {
                j++;
                i--;
                // cout << 1 << "\n";
            }
            else
            {
                i++;
                // cout << 2 << "\n";
            }
        }
        else if (i == 1)
        {
            if (j % 2 == 0)
            {
                j++;
                // cout << 3 << "\n";
            }
            else
            {
                j--;
                i++;
                // cout << 4 << "\n";
            }
        }
        else
        {
            if ((i % 2 == 0 and j % 2 == 0) or (i % 2 != 0 and j % 2 != 0))
            {
                i++;
                j--;
                // cout << 5 << "\n";
            }
            else
            {
                j++;
                i--;
                // cout << 6 << "\n";
            }
        }
        cont++;
    }
    return make_pair(i, j);
}

int main()
{
    int n;
    while (cin >> n)
    {
        auto v = solve(n);

        printf("TERM %d IS %d/%d\n", n, v.second, v.first);
    }

    return 0;
}