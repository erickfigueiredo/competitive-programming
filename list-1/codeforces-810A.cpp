// Aluno: Erick Lima Figueiredo
// MA: 98898
// Não Façam no Sapiens

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, k, aux, sum = 0;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        sum += aux;
    }

    aux = n;
    while (k != round(sum / (float)aux)) {
        sum += k;
        aux++;
    } 

    cout << aux - n << endl;
}