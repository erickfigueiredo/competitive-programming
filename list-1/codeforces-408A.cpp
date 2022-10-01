#include <iostream>

using namespace std;

int main() {
    int n, aux, acc, minSec = -1;
    cin >> n;
    int nCashier[n];

    for(int i = 0; i < n; i++) cin >> nCashier[i];
    
    for(int i = 0; i < n; i++){
        acc = 0;
        for(int j = 0; j < nCashier[i]; j++){
            cin >> aux;
            acc += aux*5;
        }
        
        acc += nCashier[i]*15;

        if(acc < minSec || minSec == -1)
            minSec = acc;
    }

    cout << minSec << endl;

    return 0;
}