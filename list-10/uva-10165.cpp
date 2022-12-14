#include <iostream>
using namespace std;

int main() {
    int nPiles, res, aux;

    while(cin >> nPiles, nPiles) {
        for(int i = 0; i < nPiles; i++){
            cin >> aux;
            if(!i) res = aux;
            else res ^= aux;
        }

        res ? cout << "Yes\n":cout<<"No\n";
    }
    return 0;
}