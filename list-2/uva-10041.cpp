// UVA: Vito's Family

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int nTests, aux, nRel, acc = 0;
    cin >> nTests;

    while(nTests--) {
        vector<int> relatives;
        cin >> nRel;

        for(int i = 0; i < nRel; i++) {
            cin >> aux;
            relatives.push_back(aux);
        }

        sort(relatives.begin(), relatives.end());

        aux =  relatives.size()/2;
        aux = relatives[aux];

        for(auto i: relatives)
            acc +=  abs(aux-i);

        cout << acc << '\n';
        acc = 0;
    }

    return 0;
}