#include <iostream>
using namespace std;

int mdc(int a, int b) {
    if (b > a) swap(a, b);

    if(!b) return 0;

    if(a/b > 1 || !(a%b)) return 1;

    return mdc(b, a-b) + 1;
}

int main() {
    int a, b, count;
    while (cin >> a >> b, a || b) {
        mdc(a, b)%2 ? cout << "Stan wins\n" : cout << "Ollie wins\n";
    }
}
