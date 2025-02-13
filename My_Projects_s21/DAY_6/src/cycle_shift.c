#include <stdio.h>

int input(int *buffer, int *length, int *c);
void output(int *buffer, int *length);
int sdvig(int *buffer, int *length, int *number, int *numbers);

int main() {
    int n, c, buffer[10], new[10];
    if (input(buffer, &n, &c) == 1) {
        printf("n/a");
        return 0;
    }
    sdvig(buffer, &n, &c, new);
    output(new, &n);
}

int input(int *a, int *n, int *c) {
    if (scanf("%d", n) != 1 || *n < 1 || *n > 10) {
        return 1;
    }
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }
    if (scanf("%d", c) != 1) {
        return 1;
    }
    return 0;
}

void output(int *a, int *n) {
    for (int i = 0; i < *n; i++) {
        if (i == *n - 1) {
            printf("%d", a[i]);
        } else
            printf("%d ", a[i]);
    }
}

int sdvig(int *buffer, int *n, int *c, int *new) {
    int s = *c % 10;
    for (int i = 0; i < *n; i++) {
        int g = (i + 10 - s) % 10;
        new[g] = buffer[i];
    }
    return 0;
}
