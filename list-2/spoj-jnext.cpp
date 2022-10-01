#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int nTests, size, p, p1, aux;
    cin >> nTests;

    while(nTests--) {
        cin >> size;
        int digits[size];

        for(int i = 0; i < size; i++)
            cin >> digits[i];

        p = -1;

        for(int i = size-1; i; i--)
            if(digits[i] > digits[i-1]){
                p = i-1;
                break;
            }

        if(p == -1)
            cout << "-1\n";
        else {
            for(p1 = size-1; digits >= 0; p1--)
                if(digits[p1] > digits[p]) break;

            aux = digits[p];
            digits[p] = digits[p1];
            digits[p1] = aux;
            
            p++;

            sort(digits+p, digits+size);

            for(int i = 0; i < size; i++)
                cout << digits[i];

            cout << '\n';
        }
    }

    return 0;
}
