#include <iostream>

using namespace std;

int main()
{
    int n, k;

    while (cin >> n >> k)
    {
        int total = n;
        while (n >= k)
        {
            n -= k;
            n++;
            total++;
        }
        if (!n)
            total++;
        cout << total << endl;
    }
    return 0;
}
