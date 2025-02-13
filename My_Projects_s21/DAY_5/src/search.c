/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
int even(int z);
int mean(int *a, int *n, int z);
int sigma(int *a, int *n, int z);
int nol(int z);

int main() {
    int n, data[NMAX];
    if (input(data, &n) != 0) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (even(data[i]) == 1 && mean(data, &n, data[i]) == 1 && nol(data[i]) == 1 &&
            sigma(data, &n, data[i]) == 1) {
            printf("%d", data[i]);
            return 0;
        }
    }
    printf("0");
    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n < 1 || *n > 10) {
        printf("n/a");
        return 1;
    }
    for (int *p = a; p - a < *n; p++) {
        scanf("%d", p);
    }
    return 0;
}

int even(int z) {
    if (z % 2 == 0) {
        return 1;
    } else
        return 0;
}

int nol(int z) {
    if (z != 0) {
        return 1;
    } else
        return 0;
}

int mean(int *a, int *n, int z) {
    double srednus = 0;
    for (int i = 0; i < *n; i++) {
        srednus += a[i];
    }
    if (z >= srednus / (*n)) {
        return 1;
    } else
        return 0;
}

int sigma(int *a, int *n, int z) {
    double variance = 0;
    double c;
    for (int i = 0; i < *n; i++) {
        c += a[i];
    }
    c = c / (*n);
    for (int i = 1; i < *n; i++) {
        variance += pow(a[i] - c, 2);
    }
    if (z <= (c) + 3 * sqrt(variance / (*n))) {
        return 1;
    } else
        return 0;
}