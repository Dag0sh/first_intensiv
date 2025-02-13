#include <stdio.h>
#include <stdlib.h>
double det(double **matrix, int n);
int input(double ***matrix, int *n, int *m);
void output(double **matrix, int n, int m);
double **make_matrix(double **matrix, int n, int m, int k, int l);
double **invert(double **matrix, int n, int m, double det_v);
double poww(double a, int n) {
    double result = 1;
    for (int i = 0; i < n; ++i) {
        result *= a;
    }
    return result;
}
int main() {
    double **matrix, **result;
    int n, m;
    double det_v = 0;
    if (!input(&matrix, &n, &m)) {
        det_v = det(matrix, n);
        if (n == m && det_v != 0) {
            result = invert(matrix, n, n, det_v);
            output(result, n, n);
            for (int i = 0; i < n; ++i) free(result[i]);
            free(result);
        } else
            printf("n/a");
        for (int i = 0; i < n; ++i) {
            free(matrix[i]);
        }
        free(matrix);
    }
    return 0;
}

int input(double ***matrix, int *n, int *m) {
    double N, M;
    int out = 0;
    int res = scanf("%lf", &N);
    res += scanf("%lf", &M);
    if (res == 2 && N == (int)N && M == (int)M && N > 0 && M > 0 && N == M) {
        *n = (int)N;
        *m = (int)M;
        *matrix = malloc(*n * sizeof(double *));
        for (int i = 0; i < *n; ++i) {
            (*matrix)[i] = malloc(*m * sizeof(double));
        }
        double tmp_digit;
        for (int i = 0; i < *n; ++i) {
            for (int j = 0; j < *m; ++j) {
                res = scanf("%lf", &tmp_digit);
                if (res != 1) out = 1;
                (*matrix)[i][j] = tmp_digit;
            }
        }
    } else {
        out = 1;
        printf("n/a");
    }
    return out;
}

void output(double **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%lf", matrix[i][j]);
            if (j != m - 1) {
                printf(" ");
            }
        }
        if (i != n - 1) printf("\n");
    }
}
double **make_matrix(double **matrix, int n, int m, int k, int l) {
    double **matrix_new;
    int m_1 = 0;
    int k_1 = 0;
    matrix_new = malloc((n - 1) * sizeof(double *));
    for (int i = 0; i < n - 1; ++i) matrix_new[i] = malloc((m - 1) * sizeof(double));
    for (int i = 0; i < n; ++i) {
        m_1 = 0;
        if (i != k) {
            for (int j = 0; j < m; ++j) {
                if (j != l) {
                    matrix_new[k_1][m_1] = matrix[i][j];
                    m_1++;
                }
            }
            k_1++;
        }
    }
    return matrix_new;
}

double det(double **matrix, int n) {
    double detv = 0;
    int napr = 1;

    if (n == 1) {
        return matrix[0][0];
    }

    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    double **newMatrix;
    for (int j = 0; j < n; j++) {
        newMatrix = make_matrix(matrix, n, n, 0, j);

        detv = detv + (napr * matrix[0][j] * det(newMatrix, n - 1));
        napr *= -1;
    }
    for (int i = 0; i < n - 1; i++) {
        free(newMatrix[i]);
    }
    free(newMatrix);

    return detv;
}
double **invert(double **matrix, int n, int m, double detv) {
    double **result_matrix;
    double **dop;
    result_matrix = malloc(n * sizeof(double *));
    for (int i = 0; i < n; ++i) result_matrix[i] = malloc(n * sizeof(double));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dop = make_matrix(matrix, n, n, i, j);
            result_matrix[j][i] = det(dop, n - 1) * poww(-1, i + j) / detv;
            for (int k = 0; k < n - 1; ++k) free(dop[k]);
            free(dop);
        }
    }
    return result_matrix;
}
