#include <iostream>
#include <cmath>

// acos(-1)
#define _USE_MATH_DEFINES

using namespace std;

int main() {
    int nTests, l, w, theta, nPieces;
    double radian, pieceL, height, a, b, rest;

    cin >> nTests;

    while (nTests--) {
        cin >> l >> w >> theta;
        radian = (theta * M_PI) / 180.0;
        if (radian != 0) {
            pieceL = w/tan(radian);

            nPieces = 1;
            while(nPieces * pieceL <= l) nPieces++;
            nPieces--;

            rest = l-(pieceL*nPieces);

            if(!((nPieces+1)%2)) height = w - rest*tan(radian);
            else height = rest*tan(radian);

            a = rest/cos(radian) + nPieces * (w/sin(radian));
            b = sqrt(pow(height, 2)+pow(l, 2));

            printf("%.3f\n", a/b);
        }
        else {
            printf("1.000\n");
        }
    }

    return 0;
}
