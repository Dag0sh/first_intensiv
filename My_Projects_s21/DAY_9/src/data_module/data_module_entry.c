
#include <stdio.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "data_process.h"

int main() {
    double *data;
    double N;
    int n;

    int res = scanf("%lf", &N);
    if (res == 1 && N == (int)N && N > 0) {
        n = (int)N;
        data = malloc(n * sizeof(double));
        if (data != NULL) {
            if (input(data, n) != 1) {
                if (normalization(data, n))
                    output(data, n);
                else {
                    printf("ERROR");
                }
            } else {
                printf("ERROR");
            }
            free(data);
        } else
            printf("ERROR");
    } else
        printf("ERROR");
    return 0;
}