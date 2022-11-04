#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, d, r, exceed;

    while (cin >> n >> d >> r)
    {
        exceed = 0;
        if (!n && !d && !r)
            break;

        vector<int> dManha(n);
        for (int i = 0; i < n; i++)
            cin >> dManha[i];

        vector<int> dTarde(n);
        for (int i = 0; i < n; i++)
            cin >> dTarde[i];

        sort(dManha.begin(), dManha.end());
        sort(dTarde.begin(), dTarde.end(), greater<int>());

        int mini = -1;
        for (int i = 0; i < n; i++)
        {
            if (dManha[i] + dTarde[i] - d > 0)
                exceed += dManha[i] + dTarde[i] - d;
        }

        cout << exceed * r << endl;
    }

    return 0;
}