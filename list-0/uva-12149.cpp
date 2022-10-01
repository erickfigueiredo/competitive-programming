// Aluno: Erick Figueiredo
// Problema: Feynman

#include <iostream>

using namespace std;

int main(){
    int n, acc;
    while(true) {
        cin >> n;
        if(!n) break;
        acc = 0;

        for(int i = 1; i <= n; i++)
            acc += (i * i);

        cout << acc << '\n';
    }

    return 0;
}
