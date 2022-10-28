#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    long long aux;
    bool possible;
    set <long long>::iterator it;

    // while(cin >> n, n) {
    while (cin >> n) {
        if (!n) break;

        set <long long> elements;
        while (n--) {
            cin >> aux;
            elements.insert(aux);
        }

        possible = false;

        // a + b + c = d --> a = d - c - b
        for (auto d = elements.rbegin(); d != elements.rend(); d++)
            for (auto c = elements.rbegin(); c != elements.rend(); c++)
                for (auto b = elements.rbegin(); b != elements.rend(); b++) {
                    if (d == c || d == b || b == c) continue;
                    aux = *d - *c - *b;

                    if (aux == *d || aux == *c || aux == *b) continue;
                    
                    it = elements.find(aux);

                    if(it != elements.end()) {
                        possible = true;
                        aux = *d;
                        goto finalStep;
                    }
                }
        
        finalStep:
        possible ? printf("%lld\n", aux) : printf("no solution\n");
    }
    return 0;
}