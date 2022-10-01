#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

int main() {
    int nSets, limit;
    stringstream ss;

    cin >> nSets;

    while (nSets--) {
        vector<int> count(10);
        cin >> limit;
        for (int i = 1; i <= limit; i++) {
            ss << i;
            for (const char a : ss.str()){
                count[a - '0']++;
            }
            ss.clear();
            ss.str("");
        }

        for (int i = 0; i < 10; i++)
            (i == 9) ? cout << count[i] << '\n' : cout << count[i] << ' ';
    }


    return 0;
}