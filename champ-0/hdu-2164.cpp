#include <iostream>

using namespace std;

int main(){
    int jogs, rods;
    char j1, j2;
    cin >> jogs;

    for(int i = 0; i < jogs; i++){
        int p1 = 0, p2 = 0;
        cin >> rods;

        for(int j = 0; j < rods; j++){
            cin >> j1 >> j2;

            if(j1 != j2) {
                if (j1== 'R' and j2 == 'P')
                    p2+=1;
                if(j1 == 'P' and j2=='R')
                    p1+=1;
                if(j1 == 'S' and j2=='R')
                    p2+=1;
                if(j1 == 'R' and j2=='S')
                    p1+=1;
                if(j1 == 'S' and j2=='P')
                    p1+=1;
                if(j1 == 'P' and j2=='S')
                    p2+=1;
            }
        }
        if(p1 == p2) cout << "TIE\n";
        else if(p1 > p2) cout << "Player 1\n";
        else cout << "Player 2\n";
    }
    return 0;
}