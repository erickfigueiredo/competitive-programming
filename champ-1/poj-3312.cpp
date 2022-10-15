#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k, acc, cont = 1;
    bool possible;
    string aux;

    while (true)
    {
        possible = true;
        acc = 0;
        cin >> n >> k;
        if (!n && !k)
            break;

        vector<int>
            members;

        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            members.push_back(aux.size());
        }

        sort(members.begin(), members.end());

        for (int i = 0; i < n; i += k)
        {
            for (int j = i; j < (i + k); j++)
            {
                //cout << members[j] << endl;
                acc += members[j];
            }
            //cout << endl;

            acc = acc / k;
            //cout << acc << endl;

            for (int j = i; j < (i + k); j++)
                if (abs(acc - members[j]) > 2)
                {
                    possible = false;
                    break;
                }
            if (!possible)
                break;
            acc = 0;
        }

        possible ? cout << "Case " << cont << ": yes\n" : cout << "Case " << cont << ": no\n";
        cont += 1;
        acc = 0;
        cout << '\n';
    }
    return 0;
}
