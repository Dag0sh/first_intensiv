#include "data_io.h"

int input(double *data, int n) {
    int res = 0;
    int out = 0;
    for (int i = 0; i < n; i++) {
        res = scanf("%lf", &data[i]);
        if (res != 1) {
            out = 1;
        }
    }
    return out;
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf", data[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
}