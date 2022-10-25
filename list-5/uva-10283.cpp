#include <iostream>
#include <cmath>
using namespace std;

#define _USE_MATH_DEFINES

int main() {
    double radius, n, theta, r, x, height, tri_area, minor_circle, blue_area, green_area;

    while(cin >> radius >> n) {
        if(radius == 0) {
            printf("%.10f %.10f %.10f\n", .0, .0, .0);
            continue;
        }

        if(n == 1) {
            printf("%.10f %.10f %.10f\n", radius, .0, .0);
            continue;
        }

        theta = 2*M_PI/n;

        x = sin(theta/2)*radius*2;
        r = (x*radius)/(2*radius+x);

        height = (r/tan(theta/2));
        tri_area = r*height;
        minor_circle = (M_PI*r*r)/((2*M_PI)/(M_PI-theta));

        blue_area = n*(tri_area-minor_circle);
        green_area =  (radius*radius*M_PI)-(r*r*M_PI*n + blue_area);

        printf("%.10f %.10f %.10f\n", r, blue_area, green_area);

    }
    return 0;
}
