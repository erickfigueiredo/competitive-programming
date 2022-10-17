#include <iostream>
#include <set>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;
ll _tam_crivo;

bitset<10000010> bs;
vector <int> primos;
set <int> p;

void crivo(ll limite) { // cria lista de primos em [0..limite]
    _tam_crivo = limite + 1; // + 1 para incluir limite
    bs.reset(); bs.flip(); // todos valendo true
    bs.set(0, false); bs.set(1, false); // exceto indices 0 e 1
    for (ll i = 2; i <= _tam_crivo; i++)
        if (bs.test((size_t)i)) {
            //corta todos os multiplos de i comecando de i*i
            for (ll j = i * i; j <= _tam_crivo; j += i)
                bs.set((size_t)j, false);
            primos.push_back((int)i); // adiciona na lista de primos
            p.insert((int)i);
        }
}

bool eh_primo(ll N) { // metodo rapido para teste de primalidade
    if (N < _tam_crivo)
        return bs.test(N); // O(1) para primos pequenos
    for (int i = 0; i < primos.size(); i++)
        if (N % primos[i] == 0)
            return false;
    return true; // demora mais quando N e’ primo
} // OBS: so funciona se N <= (ultimo primo do vector primos)^2

int main() {
    int n, aux, comp;
    crivo(1e6);

    while (cin >> n) {
        if (!n) break;

        aux = n;

        while (--aux) {
            if (!eh_primo(aux)) continue;
            comp = n - aux;
            set<int>::iterator it = p.find(comp);

            if (it != p.end()) break;
        }

        aux ? printf("%d = %d + %d\n", n, comp, aux) : printf("Goldbach's conjecture is wrong!");
    }

    return 0;
}
