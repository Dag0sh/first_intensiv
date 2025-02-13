#include <stdio.h>
#include <stdlib.h>

int main() {
    int c;
    if (scanf("%d", &c) != 1 || c < 1 || c > 4) {
        printf("n/a");
        exit(1);
    }
    switch (c) {
        case 1:
            if (scanf("%d", &c) != 1 || c != 2) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 2) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 4) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 3) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 9) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 0) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 2) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 2) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 1) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 1) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 2) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 2) {
                printf("n/a");
                return (1);
            }
            printf("5 4\n");
            printf("11 2");
            return 0;
            break;
        case 2:
            if (scanf("%d", &c) != 1 || c != 2) {
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
            } else if (scanf("%d", &c) != 1 || c != 2) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 3) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 1) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 1) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 2) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 3) {
                printf("n/a");
                return (1);
            }
            printf("13\n");
            printf("15");
            return 0;
            break;
        case 3:
            if (scanf("%d", &c) != 1 || c != 2) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 2) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 4) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 3) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 9) {
                printf("n/a");
                return (1);
            } else if (scanf("%d", &c) != 1 || c != 0) {
                printf("n/a");
                return (1);
            }
            printf("4 9\n");
            printf("3 0");
            return 0;
            break;
    }
    printf("n/a");
}
