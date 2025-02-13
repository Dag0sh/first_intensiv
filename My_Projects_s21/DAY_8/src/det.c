#include <math.h>
#include <stdio.h>
#include <stdlib.h>
double det(double **matrix, int n);
int input(double ***matrix, int *n, int *m);
double **make_matrix(double **matrix, int n, int m, int k, int l);

int main() {
    double **matrix;
    int n, m;
    double det_v = 0;
    if (!input(&matrix, &n, &m)) {
        det_v = det(matrix, n);
        if (n == m)
            printf("%lf", det_v);
        else
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
    double det_v = 0;
    int degree = 1;

    if (n == 1) {
        return matrix[0][0];
    }

    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    double **newMatrix;
    for (int j = 0; j < n; j++) {
        newMatrix = make_matrix(matrix, n, n, 0, j);

        det_v = det_v + (degree * matrix[0][j] * det(newMatrix, n - 1));
        degree *= -1;
    }

    for (int i = 0; i < n - 1; i++) {
        free(newMatrix[i]);
    }
    free(newMatrix);

    return det_v;
}
