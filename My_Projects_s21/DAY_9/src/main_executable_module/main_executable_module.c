#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

int main() {
    double *data = NULL;
    int n;
    double N;

    int res = scanf("%lf", &N);
    if (res == 1 && N == (int)N && N > 0) {
        n = (int)N;
        data = malloc(n * sizeof(double));
        if (data != NULL) {
            printf("LOAD DATA...\n");
            if (input(data, n) != 1) {
                printf("RAW DATA:\n\t");
                output(data, n);

                printf("\nNORMALIZED DATA:\n\t");
                if (normalization(data, n)) {
                    output(data, n);

                    printf("\nSORTED NORMALIZED DATA:\n\t");
                    sort(data, n);
                    output(data, n);

                    printf("\nFINAL DECISION:\n\t");
                    if (make_decision(data, n))
                        printf("YES");
                    else
                        printf("NO");
                } else
                    printf("ERROR");
            }
            printf("ERROR");
            free(data);
        } else
            printf("ERROR");
    } else
        printf("ERROR");

    return 0;
}
