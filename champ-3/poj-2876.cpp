#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void makeFrac(int begin, int end, const string& str) {
    int offset = (end - begin + 1) / 3;

    if (!offset) {
        cout << str[begin];
        return;
    }

    makeFrac(begin, begin+offset, str);
    for(int i = 0; i < offset; i++) cout << ' ';
    makeFrac(begin+2*offset, end, str);
}

int main() {
    int exp;
    while (cin >> exp) {
        string frac;
        exp = pow(3., exp);

        for (int i = 0; i < exp; i++) frac += '-';

        makeFrac(0, frac.size(), frac);
        cout << '\n';
    }
}