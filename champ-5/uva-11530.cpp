#include <bits/stdc++.h>

using namespace std;

int main() {
    map<char, int> key = { {'a', 1},{'b', 2},{'c', 3},{'d', 1},{'e', 2},{'f', 3},{'g', 1},
    {'h', 2},{'i', 3},{'j', 1},{'k', 2},{'l', 3},{'m', 1},{'n', 2},{'o', 3},{'p', 1},
    {'q', 2},{'r', 3},{'s', 4},{'t', 1},{'u', 2},{'v', 3},{'w', 1},{'x', 2},{'y', 3},
    {'z', 4},{' ', 1} };

    int n, acc;
    cin >> n;
    string phrase;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        acc = 0;
        getline(cin, phrase);
        for (char c : phrase)
            acc += key[c];

        printf("Case #%d: %d\n", i, acc);
    }

    return 0;
}