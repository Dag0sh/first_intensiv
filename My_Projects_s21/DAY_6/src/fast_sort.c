#include <stdio.h>

int input(int *a);
void output(int *a);
void qsort(int *data, int left, int right);
void qsortoutput(int *data, int left, int right);
void hipsort(int *arr);
void heap(int *arr, int n, int i);
void copy(int *a, int *arr);

int main() {
    int data[10], arr[10];
    if (input(data) == 0) {
        return 0;
    };
    copy(data, arr);
    qsortoutput(data, 0, 9);
    printf("\n");
    hipsort(arr);
    output(arr);
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
}

void qsortoutput(int *data, int left, int right) {
    qsort(data, left, right);
    output(data);
}

void hipsort(int *arr) {
    int n = 10;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heap(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heap(arr, i, 0);
    }
}

void heap(int *arr, int n, int i) {
    int big = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[big]) {
        big = l;
    }
    if (r < n && arr[r] > arr[big]) {
        big = r;
    }
    if (big != i) {
        int tmp = arr[i];
        arr[i] = arr[big];
        arr[big] = tmp;
        heap(arr, n, big);
    }
}

void copy(int *data, int *arr) {
    for (int i = 0; i < 10; i++) {
        arr[i] = data[i];
    }
}