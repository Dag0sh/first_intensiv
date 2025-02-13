#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "decision.h"

int main() {
    double *data;
    int n;
    double N;

    int res = scanf("%lf", &N);
    if (res == 1 && N == (int)N && N > 0) {
        n = (int)N;
        data = malloc(n * sizeof(double));
        if (data != NULL) {
            if (input(data, n) != 1) {
                if (make_decision(data, n))
                    printf("YES");
                else
                    printf("NO");
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