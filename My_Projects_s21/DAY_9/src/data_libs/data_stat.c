#include "data_stat.h"

double max(double *data, int n) {
    int maximus = data[0];
    for (int i = 0; i < n; i++) {
        if (maximus < data[i]) {
            maximus = data[i];
        }
    }
    return maximus;
}
double min(double *data, int n) {
    int minimus = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] < minimus) {
            minimus = data[i];
        }
    }
    return minimus;
}

double mean(double *data, int n) {
    double srednus = data[0];
    for (int i = 1; i < n; i++) {
        srednus += data[i];
    }
    return srednus / (n);
}

double variance(double *data, int n) {
    double variance = 0.0;
    double c = mean(data, n);
    for (int i = 0; i < n; i++) {
        variance += (data[i] - c) * (data[i] - c);
    }
    return variance / (n);
}

void sort(double *data, int n) {
    for (int i = 0; i < n - 1; i++) {
        // сравниваем два соседних элемента.
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                // если они идут в неправильном порядке, то
                //  меняем их местами.
                double tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
}