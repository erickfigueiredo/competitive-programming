#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> grid;

int main() {
    int t, nObjects, nPeople, person, p, w, acc;

    cin >> t;
    while (t--) {
        cin >> nObjects;
        vector<pair<int, int>> objects(nObjects);
        for (int i = 0; i < nObjects; i++) {
            cin >> p >> w;
            objects[i] = { p, w };
        }

        grid feasible(nObjects + 1, vector<int>(31, -1));
        for (int i = 0; i < 31; i++) feasible[0][i] = 0;
        for (int i = 0; i < nObjects + 1; i++) feasible[i][0] = 0;

        for (int i = 1; i < nObjects + 1; i++)
            for (int j = 1; j < 31; j++) {
                if (feasible[i][j] != -1) continue;
                feasible[i][j] = j - objects[i - 1].second >= 0 ? max(feasible[i - 1][j], objects[i - 1].first + feasible[i - 1][j - objects[i - 1].second]) : feasible[i - 1][j];
            }

        /*for (int i = 0; i < nObjects + 1; i++){
            for (int j = 0; j < 31; j++) 
                cout << feasible[i][j] << ' ';

            cout << '\n';
        }*/

        cin >> nPeople;
        acc = 0;
        while(nPeople--) {
            cin >> person;
            acc += feasible[nObjects][person];
        }

        cout << acc << '\n';
    }

    return 0;
}