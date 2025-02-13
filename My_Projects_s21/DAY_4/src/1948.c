#include <math.h>
#include <stdio.h>

int ostat(int a, int b);
int find_del(int a);
int checkonp(int b);

int main() {
    int a;
    if (scanf("%d", &a) != 1 || a < 0) {
        printf("n/a");
        return 0;
    }
    if (checkonp(a) == 1) {
        printf("%d", a);
        return 0;
    }
    printf("%d", find_del(a));
    return 0;
}

int find_del(int a) {
    int b = a - 1;
    for (b; b > 0; b--) {
        if (ostat(a, b) == 0) {
            if (checkonp(b) == 1) {
                return b;
            }
        }
    }
}

int ostat(int a, int b) {
    while (a >= b) {
        a -= b;
    }
    return a;
}

int checkonp(int b) {
    int c = b - 1;
    for (c; c > 1; c--) {
        if (ostat(b, c) == 0) {
            return 0;
        }
    }
    return 1;
}