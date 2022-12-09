#include <iostream>
#include <vector>

using namespace std;

void findNextBead(vector <vector<int>>& m, int& sumE, const int row, vector <int>& necklace) {
    for (int i = 0; i < 50; i++) {
        if (m[row][i]) {
            m[row][i]--;
            m[i][row]--;

            sumE--; 

            findNextBead(m, sumE, i, necklace);
        }
    }

    necklace.push_back(row + 1);

}

int main() {
    int testCases, nBeads, c1, c2, sumEdge = 0;
    bool isEulerian = true;

    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        
        vector <vector <int>> adjMatrix(50, vector<int>(50));

        vector<int> colourDegree(50);

        cin >> nBeads;

        for (int j = 0; j < nBeads; j++) {
            cin >> c1 >> c2;

            c1--;
            c2--;

            colourDegree[c1]++;
            colourDegree[c2]++;

            adjMatrix[c1][c2]++;
            adjMatrix[c2][c1]++;

            sumEdge++;
        }

        printf("Case #%d\n", i + 1);

        for (int i = 0; i < 50; i++)
            if (colourDegree[i] % 2 != 0) {
                isEulerian = false;
                break;
            }

        if (!isEulerian) {
            cout << "some beads may be lost\n\n";

            isEulerian = true;
            sumEdge = 0;

            continue;
        }

        vector <int> orderedNecklace;

        findNextBead(adjMatrix, sumEdge, c2, orderedNecklace);

        if (!sumEdge) {
            for (int k = 0; k < nBeads; k++)
                cout << orderedNecklace[k] << ' ' << orderedNecklace[k + 1] << endl;
        }
        else { cout << "some beads may be lost\n"; }
        cout << "\n";

        isEulerian = true;
        sumEdge = 0;
    }
    return 0;
}
