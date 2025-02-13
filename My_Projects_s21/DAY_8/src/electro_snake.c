#include <stdio.h>
#include <stdlib.h>

int min_element(int **matrix, int n, int m, int *min_i, int *min_j);
void sort_vertical(int **matrix, int n, int m, int ***result_matrix);
void sort_horizontal(int **matrix, int n, int m, int ***result_matrix);
int input(int ***matrix, int *n, int *m);
void output(int **matrix, int n, int m);

int min_element(int **matrix, int n, int m, int *min_i, int *min_j) {
    int min = 10000000;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                *min_i = i;
                *min_j = j;
            }
        }
    }
    matrix[*min_i][*min_j] = 10000000;
    return min;
}

void sort_vertical(int **matrix, int n, int m, int ***result_matrix) {
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            int min_i, min_j;
            (*result_matrix)[(j % 2 == 0 ? i : n - i - 1)][j] = min_element(matrix, n, m, &min_i, &min_j);
        }
    }
}

void sort_horizontal(int **matrix, int n, int m, int ***result_matrix) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int min_i, min_j;
            (*result_matrix)[i][(i % 2 == 0 ? j : m - j - 1)] = min_element(matrix, n, m, &min_i, &min_j);
        }
    }
}

int input(int ***matrix, int *n, int *m) {
    double N, M;
    int out = 0;
    int result = scanf("%lf", &N);
    result += scanf("%lf", &M);
    if (result == 2 && N == (int)N && M == (int)M && N > 0 && M > 0) {
        *n = (int)N;
        *m = (int)M;
        *matrix = malloc(*n * sizeof(int *));
        for (int i = 0; i < *n; ++i) {
            (*matrix)[i] = malloc(*m * sizeof(int));
        }
        double tmp_digit;
        for (int i = 0; i < *n; ++i) {
            for (int j = 0; j < *m; ++j) {
                result = scanf("%lf", &tmp_digit);
                if (result != 1 || tmp_digit != (int)tmp_digit) out = 1;
                (*matrix)[i][j] = (int)tmp_digit;
            }
        }
    } else {
        out = 1;
        printf("n/a");
    }
    return out;
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if (j != m - 1) {
                printf(" ");
            }
        }
        if (i != n - 1) printf("\n");
    }
}

void copy(int **matrix, int n, int m, int ***copym) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            (*copym)[i][j] = matrix[i][j];
        }
    }
}
int main() {
    int **matrix, **result, **copym;
    int n, m;

    if (!input(&matrix, &n, &m)) {
        result = malloc(n * sizeof(int *));
        copym = malloc(n * sizeof(int *));
        for (int i = 0; i < n; ++i) {
            result[i] = malloc(m * sizeof(int));
            copym[i] = malloc(m * sizeof(int));
        }
        copy(matrix, n, m, &copym);
        sort_vertical(matrix, n, m, &result);
        output(result, n, m);

        printf("\n\n");

        sort_horizontal(copym, n, m, &result);
        output(result, n, m);

        for (int i = 0; i < n; ++i) {
            free(matrix[i]);
            free(result[i]);
            free(copym[i]);
        }
        free(matrix);
        free(copym);
        free(result);
    }

    return 0;
}
