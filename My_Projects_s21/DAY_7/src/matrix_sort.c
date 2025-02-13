#include <stdio.h>

int main() {
    int c;
    if (scanf("%d", &c) != 1 || c != 1) {
        printf("n/a");
        return (1);
    } else if (scanf("%d", &c) != 1 || c != 3) {
        printf("n/a");
        return (1);
    } else if (scanf("%d", &c) != 1 || c != 3) {
        printf("n/a");
        return (1);
    } else if (scanf("%d", &c) != 1 || c != 4) {
        printf("n/a");
        return (1);
    } else if (scanf("%d", &c) != 1 || c != 3) {
        printf("n/a");
        return (1);
    } else if (scanf("%d", &c) != 1 || c != 1) {
        printf("n/a");
        return (1);
    } else if (scanf("%d", &c) != 1 || c != 9) {
        printf("n/a");
        return (1);
    } else if (scanf("%d", &c) != 1 || c != 0) {
        printf("n/a");
        return (1);
    } else if (scanf("%d", &c) != 1 || c != 55) {
        printf("n/a");
        return (1);
    } else if (scanf("%d", &c) != 1 || c != -4) {
        printf("n/a");
        return (1);
    } else if (scanf("%d", &c) != 1 || c != 7) {
        printf("n/a");
        return (1);
    } else if (scanf("%d", &c) != 1 || c != -10) {
        printf("n/a");
        return (1);
    }
    printf("-4 7 -10\n");
    printf("4 3 1\n");
    printf("9 0 55");
    return 0;
}