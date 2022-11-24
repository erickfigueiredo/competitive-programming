#include <bits/stdc++.h>

using namespace std;

int main() {
    int nTests, n, up, down;

    cin >> nTests;
    for(int j = 0; j < nTests; j++){
        cin >> n;
        vector<int> walls(n);
        
        up = 0;
        down = 0;
        for(int i = 0; i < n; i++) {
            cin >>walls[i];

            if(i > 0) {
                if(walls[i-1] > walls[i]) down++;
                else if(walls[i-1] < walls[i]) up++;
            }
        }

        printf("Case %d: %d %d\n", j+1, up, down);
    }

    return 0;
}
