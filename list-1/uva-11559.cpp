#include <iostream>
using namespace std;

int main() {
    // People, budget, hotels, weeks;
    int n, b, h, w;
    int aux, cost, minCost;
    bool possible;

    while(cin >> n >> b >> h >> w) {
        minCost = -1;
        
        for(int i = 0; i < h; i++) {
            possible = false;
            cin >> cost;
            cost *= n;

            for(int j = 0; j < w; j++) {
                cin >> aux;
                if(aux >= n && cost <= b) possible = true;
            }

            if(possible && (minCost == -1 || cost < minCost))
                minCost = cost;
        }

        minCost != -1 ? cout << minCost << endl : cout << "stay home\n";
    }
    return 0;
}