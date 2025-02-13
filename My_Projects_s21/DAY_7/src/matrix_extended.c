#include <stdio.h>
#include <stdlib.h>
#define max 100;

int inputss(int *n, int *m);
int met1(int arr[100][100], int n, int m);
int met2(int ***pointer_array, int n, int m);
int met3(int ***pointer_array, int n, int m);
int met4(int ***pointer_array, int n, int m);

int main() {
    int arr[100][100];
    int **data, n, m;
    int c;
    if (scanf("%d", &c) != 1 || c < 1 || c > 4) {
        printf("n/a");
        exit(1);
    }
    if (inputss(&n, &m) == 1) {
        printf("n/a");
        exit(1);
    }

    switch (c) {
        case 1:
            met1(arr, n, m);
            break;
        case 2:
            met2(&data, n, m);
            break;
        case 3:
            met3(&data, n, m);
            break;
        case 4:
            met4(&data, n, m);
            break;
    }
    return 0;
}

int inputss(int *n, int *m) {
    int stat;
    if (scanf("%d", n) != 1 || *n < 1 || *n > 100) {
        stat = 1;
    } else if (scanf("%d", m) != 1 || *m < 1 || *m > 100) {
        stat = 1;
    }
    return stat;
}

int met4(int ***pointer_array, int n, int m) {
    *pointer_array = malloc(n * sizeof(int *));
    if (*pointer_array == NULL) {
        printf("n/a");
        free(*pointer_array);
        exit(1);
    }
    int *values_array = malloc(m * n * sizeof(int));
    if (values_array == NULL) {
        printf("n/a");
        free(*pointer_array);
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        (*pointer_array)[i] = values_array + m * i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &(*pointer_array)[i][j]) != 1) {
                printf("n/a");
                free(values_array);
                free(*pointer_array);
                exit(1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1) {
                printf("%d", (*pointer_array)[i][j]);
            } else
                printf("%d ", (*pointer_array)[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        int c = (*pointer_array)[i][0];
        for (int j = 1; j < m; j++) {
            if (c < (*pointer_array)[i][j]) {
                c = (*pointer_array)[i][j];
            }
        }
        if (i == n - 1) {
            printf("%d\n", c);
        } else
            printf("%d ", c);
    }
    for (int j = 0; j < m; j++) {
        int c = (*pointer_array)[0][j];
        for (int i = 1; i < n; i++) {
            if (c > (*pointer_array)[i][j]) {
                c = (*pointer_array)[i][j];
            }
        }
        if (j == n - 1) {
            printf("%d", c);
        } else
            printf("%d ", c);
    }

    free(values_array);
    free(*pointer_array);
    return (1);
}

int met3(int ***pointer_array, int n, int m) {
    *pointer_array = malloc(n * sizeof(int *));
    if (*pointer_array == NULL) {
        printf("n/a");
        free(*pointer_array);
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        (*pointer_array)[i] = malloc(m * sizeof(int *));

        if (*pointer_array == NULL) {
            printf("n/a");
            free(*pointer_array);
            exit(1);
            for (int j = 0; j < i; j++) {
                free((*pointer_array)[j]);
            }
            free(*pointer_array);
            exit(1);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &(*pointer_array)[i][j]) != 1) {
                printf("n/a");
                for (int k = 0; k <= i; k++) {
                    free((*pointer_array)[k]);
                }
                free(*pointer_array);
                exit(1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1) {
                printf("%d", (*pointer_array)[i][j]);
            } else
                printf("%d ", (*pointer_array)[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        int c = (*pointer_array)[i][0];
        for (int j = 1; j < m; j++) {
            if (c < (*pointer_array)[i][j]) {
                c = (*pointer_array)[i][j];
            }
        }
        if (i == n - 1) {
            printf("%d\n", c);
        } else
            printf("%d ", c);
    }
    for (int j = 0; j < m; j++) {
        int c = (*pointer_array)[0][j];
        for (int i = 1; i < n; i++) {
            if (c > (*pointer_array)[i][j]) {
                c = (*pointer_array)[i][j];
            }
        }
        if (j == n - 1) {
            printf("%d", c);
        } else
            printf("%d ", c);
    }

    for (int i = 0; i < n; i++) {
        free((*pointer_array)[i]);
    }
    free(*pointer_array);
    return (1);
}
int met2(int ***pointer_array, int n, int m) {
    *pointer_array = malloc(n * sizeof(int *));
    if (*pointer_array == NULL) {
        printf("n/a");
        free(*pointer_array);
        exit(1);
    }

    int *ptr = malloc(n * m * sizeof(int));
    if (ptr == NULL) {
        printf("n/a");
        free(*pointer_array);
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        (*pointer_array)[i] = ptr + m * i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &(*pointer_array)[i][j]) != 1) {
                printf("n/a");
                free(ptr);
                free(*pointer_array);
                exit(1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1) {
                printf("%d", (*pointer_array)[i][j]);
            } else
                printf("%d ", (*pointer_array)[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        int c = (*pointer_array)[i][0];
        for (int j = 1; j < m; j++) {
            if (c < (*pointer_array)[i][j]) {
                c = (*pointer_array)[i][j];
            }
        }
        if (i == n - 1) {
            printf("%d\n", c);
        } else
            printf("%d ", c);
    }
    for (int j = 0; j < m; j++) {
        int c = (*pointer_array)[0][j];
        for (int i = 1; i < n; i++) {
            if (c > (*pointer_array)[i][j]) {
                c = (*pointer_array)[i][j];
            }
        }
        if (j == n - 1) {
            printf("%d", c);
        } else
            printf("%d ", c);
    }
    free(ptr);
    free(*pointer_array);
    return (1);
}

int met1(int arr[100][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (scanf("%d", &arr[i][j]) != 1) {
                printf("n/a");
                exit(1);
            }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1) {
                printf("%d", arr[i][j]);
            } else
                printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        int c = arr[i][0];
        for (int j = 1; j < m; j++) {
            if (c < arr[i][j]) {
                c = arr[i][j];
            }
        }
        if (i == n - 1) {
            printf("%d\n", c);
        } else
            printf("%d ", c);
    }
    for (int j = 0; j < m; j++) {
        int c = arr[0][j];
        for (int i = 1; i < n; i++) {
            if (c > arr[i][j]) {
                c = arr[i][j];
            }
        }
        if (j == n - 1) {
            printf("%d", c);
        } else
            printf("%d ", c);
    }
    return 0;
}
