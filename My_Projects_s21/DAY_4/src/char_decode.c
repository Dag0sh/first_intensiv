#include <stdio.h>

void cod();
void decod();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("n/a");
        return 0;
    }
    if (*argv[1] != '0' && *argv[1] != '1') {
        printf("n/a");
        return 0;
    }
    if (*argv[1] == '0') {
        cod();
    } else {
        decod();
    }
}

void cod() {
    char c1, c2;
    for (;;) {
        c1 = getchar();
        c2 = getchar();
        if (c2 != ' ' && c2 != '\n') {
            printf("n/a");
            return;
        }
        printf("%02X ", (unsigned char)c1);
        if (c2 == '\n') {
            return;
        }
    }
}

void decod() {
    char buf[3], c2;
    for (;;) {
        if (scanf("%2s", buf) != 1) {
            printf("n/a");
            return;
        }
        c2 = getchar();
        int elem;
        sscanf(buf, "%x", &elem);
        if (elem < 0 || elem > 255) {
            printf("n/a");
            return;
        }
        if (c2 != ' ' && c2 != '\n') {
            printf("n/a");
            return;
        }
        printf("%c ", (char)elem);
        if (c2 == '\n') {
            return;
        }
    }
}