#include <iostream>
#include <cmath>

#define _USE_MATH_DEFINES

using namespace std;

int p, q, r, s, t, u;

double calc(double x) {
    return p * pow(M_E, -x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2) + u;
}

bool applyPredicate(double x) {
    return calc(x) < 1e-9;
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
    while (cin >> p >> q >> r >> s >> t >> u) {
        // verifica se toca o eixo X
        if (calc(0) * calc(1) <= 0) printf("%.4f\n", realBinarySearch(0, 1));
        else printf("No solution\n");
    }
    return 0;
}
