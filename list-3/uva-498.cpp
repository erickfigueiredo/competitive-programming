#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

long long int horner(const vector<long long int>& poly, long long int x) {
    long long int res = poly[0];

    for (int i = 1; i < poly.size(); i++)
        res = res * x + poly[i];

    return res;
}

int main() {
    long long int aux;
    string input;
    
    stringstream b1, b2;
    while (getline(cin, input)) {
        b1 << input;
        vector <long long int> polynomial;
        vector <long long int> xValues;

        while (b1 >> aux)
            polynomial.push_back(aux);

        getline(cin, input);
        b2 << input;

        while (b2 >> aux)
            xValues.push_back(aux);

        for (int i = 0; i < xValues.size(); i++)
            (i == xValues.size() - 1) ? cout << horner(polynomial, xValues[i]) << '\n' :
            cout << horner(polynomial, xValues[i]) << ' ';

        b1.clear();
        b1.str("");
        b2.clear();
        b2.str("");
    }

    return 0;
}