// Aluno: Erick Figueiredo
// Problema: Pascal Library

#include <iostream>

using namespace std;

int main() {
    int al, din, acc;
    bool attended = false;

    while (true) {
        cin >> al >> din;
        if (!(al || din)) break;

        int guestsDinner[din][al];
        for (int i = 0; i < din; i++)
            for (int j = 0; j < al; j++)
                cin >> guestsDinner[i][j];

        for (int i = 0; i < al; i++) {
            acc = 0;
            for (int j = 0; j < din; j++)
                acc += guestsDinner[j][i];
            
            if(acc == din) {
                attended = true;
                break;
            }
        }

        attended ? cout << "yes\n" : cout << "no\n";
        attended = false;
    }
    return 0;
}