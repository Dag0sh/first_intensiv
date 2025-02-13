#include <stdio.h>
#include <stdlib.h>

int input(int **a, int *n);
void output(int *a, int n);
int select(int *a);
void quicksort(int *data, int left, int right);

int main() {
    int *data = NULL, n;
    if (input(&data, &n) == 0) {
        return 0;
    };
    quicksort(data, 0, n - 1);
    output(data, n);
    free(data);
    return 0;
}

int input(int **a, int *n) {
    if (scanf("%d", n) != 1 || *n < 1 || *n > 10) {
        printf("n/a");
        return 0;
    }
    *a = (int *)malloc(*n * sizeof(int));
    if (*a == NULL) {
        printf("n/a");
        free(*a);
        return 0;
    }
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &(*a)[i]) != 1) {
            printf("n/a");
            return 0;
        }
    }
    return 1;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d", a[i]);
        } else
            printf("%d ", a[i]);
    }
}

void quicksort(int *data, int left, int right) {
    if (left < right) {
        int l = left;
        int r = right;
        int midle = data[(l + r) / 2];
        do {
            while (data[l] < midle) {
                l++;
            }
            while (data[r] > midle) {
                r--;
            }
            if (l <= r) {
                int t = data[l];
                data[l] = data[r];
                data[r] = t;
                l++;
                r--;
            }
        } while (l < r);
        quicksort(data, left, r);
        quicksort(data, l, right);
    }
    return;
}
