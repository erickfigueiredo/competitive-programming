#include <iostream>
#include <vector>
#include <cmath>

#define _USE_MATH_DEFINES

using namespace std;

vector <int> arr;

double calc(double irr) {
    double res = 0;
    for (int i = 0; i < arr.size(); i++)
        res += arr[i] / pow((1 + irr), i);
    
    return res;
}

bool applyPredicate(double irr) {
    return calc(irr) < 1e-9;
}

double realBinarySearch(double lo, double hi) {
    for (int i = 0;i < 50;i++) {
        double mid = lo + (hi - lo) / 2;

        if (applyPredicate(mid)) hi = mid;
        else lo = mid;
    }

    return lo;
}

int main() {
    int t, aux;
    double r;
    while (cin >> t) {
        if (!t) break;
        vector<int> v(t);

        for (int i = 0; i < t + 1; i++) {
            cin >> aux;
            arr.push_back(aux);
        }
        r = realBinarySearch(-1, 1e4);

        if(applyPredicate(r) <= 1e-9) printf("%.2f\n", r);
        else printf("No\n");

        arr.clear();
    }

    return 0;
}