#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
int max(int *a, int *n);
int min(int *a, int *n);
double mean(int *a, int *n);
double variance(int *a, int *n);

void output_result(int max, int min, double mean, double variance);

int main() {
    int n, data[NMAX];
    if (input(data, &n) != 0) {
        return 0;
    }
    if (n == 1) {
        printf("%d %d %d %d", data[0], data[0], data[0], data[0]);
        return 0;
    }
    output(data, &n);
    output_result(max(data, &n), min(data, &n), mean(data, &n), variance(data, &n));

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

void output(int *a, int *n) {
    for (int i = 0; i < *n; i++) {
        if (i == *n - 1) {
            printf("%d\n", a[i]);
        } else
            printf("%d ", a[i]);
    }
}

int max(int *a, int *n) {
    int maximus = a[0];
    for (int i = 1; i < *n; i++) {
        if (a[i] < maximus) {
            maximus = a[i];
        }
    }
    return maximus;
}

int min(int *a, int *n) {
    int minimus = a[0];
    for (int i = 1; i < *n; i++) {
        if (a[i] > minimus) {
            minimus = a[i];
        }
    }
    return minimus;
}

double mean(int *a, int *n) {
    double srednus = a[0];
    for (int i = 1; i < *n; i++) {
        srednus += a[i];
    }
    return srednus / (*n);
}

double variance(int *a, int *n) {
    double variance = 0.0;
    double c = mean(a, n);
    for (int i = 0; i < *n; i++) {
        variance += (a[i] - c) * (a[i] - c);
    }
    return variance / (*n);
}

void output_result(int max, int min, double mean, double variance) {
    printf("%d %d %.6lf %.6lf", max, min, mean, variance);
    return;
}