#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compara(pair<string, pair<int, int>> &a, pair<string, pair<int, int>> &b)
{
    if (a.second.first == b.second.first)
    {
        return a.second.second < b.second.second;
    }

    return a.second.first > b.second.first;
}

int main()
{
    int n, sub, time;

    cin >> n;
    vector<pair<string, pair<int, int>>> teams;

    while (n--)
    {
        pair<string, pair<int, int>> aux;
        aux.second.first = 0;
        aux.second.second = 0;

        cin >> aux.first;

        for (int i = 0; i < 4; i++)
        {
            cin >> sub >> time;
            //cout << sub << ' ' << time << endl;
            if (time != 0)
            {
                aux.second.first++;
                aux.second.second += time + 20 * (sub - 1);
            }
        }
        teams.push_back(aux);
    }

    sort(teams.begin(), teams.end(), compara);

    cout << teams[0].first << ' ' << teams[0].second.first << ' ' << teams[0].second.second << '\n';
}