#include <math.h>
#include <stdio.h>

double anz(double x);
double ber(double x);
double gip(double x);

int main() {
    double x, pi = 3.14159265358979323846;
    x = -pi;
    for (int i = 1; i <= 42; i++) {
        if (ber(x) > 0) {
            printf("%.7lf | %.7lf | %.7lf | %.7lf \n", x, anz(x), ber(x), gip(x));
        } else {
            printf("%.7lf |%.7lf | - | %.7lf \n", x, anz(x), gip(x));
        }
        x = x + (2 * pi) / 41;
    }
}

double anz(double x) {
    x = pow(1 + pow(x, 2), -1);
    return x;
}

double ber(double x) {
    x = sqrt(sqrt(1 + 4 * pow(x, 2)) - pow(x, 2) - 1);
    return x;
}

double gip(double x) {
    x = pow(pow(x, 2), -1);
    return x;
}