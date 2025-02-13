#include <math.h>
#include <stdio.h>

int fib(int n);

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("n/a");
        return 0;
    }
    printf("%d", fib(n));
}

int fib(int n) {
    switch (n) {
        case 1:
            return (1);
        case 2:
            return (1);
        default:
            return (fib(n - 1) + fib(n - 2));
    }
}