#include <stdio.h>
#define n 10

int input(int *a);
void output(int *a);
int select(int *a);
void qsort(int *data, int left, int right);

int main() {
    int data[10];
    if (input(data) == 0) {
        return 0;
    };
    qsort(data, 0, n - 1);
    output(data);

    return 0;
}

int input(int *a) {
    for (int i = 0; i < 10; i++) {
        if (scanf("%d", &a[i]) != 1) {
            printf("n/a");
            return 0;
        }
    }
    return 1;
}

void output(int *a) {
    for (int i = 0; i < 10; i++) {
        if (i == 9) {
            printf("%d", a[i]);
        } else
            printf("%d ", a[i]);
    }
}

void qsort(int *data, int left, int right) {
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
        qsort(data, left, r);
        qsort(data, l, right);
    }
    return;
}