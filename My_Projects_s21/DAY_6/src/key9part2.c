#include <stdio.h>
#include <stdlib.h>

#define LEN 100

void sum(int *buff1, int *len1, int *buff2, int *len2, int *result, int *result_length);
// void sub(int *buff1, int *len1, int *buff2, int *len2, int *result, int *result_length);
int input(int *a, int *n);
void output(int *a, int *n);
void perevor(int *a, int *n);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
    int buf[LEN], n, new[LEN], l, ress[LEN], resls;
    if (input(buf, &n) == 1) {
        return 0;
    };
    if (input(new, &l) == 1) {
        return 0;
    }
    sum(buf, &n, new, &l, ress, &resls);
    // sub(buf, &n, new, &l, resv, &reslv);
    return 0;
}

int input(int *a, int *n) {
    int i = 0, elem;
    int c;
    while ((i < LEN) && (c = getchar()) != '\n') {
        if (c != ' ') {
            if (c < '0' || c > '9') {
                printf("n/a");
                return 1;
            }
            elem = c - '0';
            a[i] = (int)elem;
            i++;
        }
    }
    *n = i;
    return 0;
}

void output(int *a, int *n) {
    for (int i = 0; i < *n; i++) {
        if (i == *n - 1) {
            printf("%d\n", a[i]);
        } else
            printf("%d ", a[i]);
    }
}

void perevor(int *a, int *n) {
    int left = 0;
    int right = *n - 1;
    while (left < right) {
        int tmp = a[left];
        a[left] = a[right];
        a[right] = tmp;
        left++;
        right--;
    }
    return;
}

void sum(int *buff1, int *len1, int *buff2, int *len2, int *result, int *result_length) {
    int i = 0, j = 0, ost = 0;
    perevor(buff1, len1);
    perevor(buff2, len2);
    if (*len1 > *len2) {
        while (i < *len1 && i < *len2) {
            result[i] += (buff1[i] + buff2[i] + ost) % 10;
            ost = (buff1[i] + buff2[i] + ost) / 10;
            i++;
            j++;
        }
        if ((ost) != 0) {
            buff1[*len2] += 1;
        }
        for (i = *len2; i < *len1; i++) {
            result[i] = buff1[i];
            j++;
        }
    }
    if (*len2 > *len1) {
        while (i < *len1 && i < *len2) {
            result[i] += (buff1[i] + buff2[i] + ost) % 10;
            ost = (buff1[i] + buff2[i] + ost) / 10;
            i++;
            j++;
        }
        if ((ost) != 0) {
            buff2[*len1] += 1;
        }
        for (i = *len1; i < *len2; i++) {
            result[i] = buff2[i];
            j++;
        }
    }
    if (*len2 == *len1) {
        while (i < *len1 && i < *len2) {
            result[i] += (buff1[i] + buff2[i] + ost) % 10;
            ost = (buff1[i] + buff2[i] + ost) / 10;
            i++;
            j++;
        }
        if ((ost) != 0) {
            result[*len1] = 1;
            j++;
        }
    }
    *result_length = j;
    perevor(result, result_length);
    output(result, result_length);
    return;
}

/*void sub(int *buff1, int *len1, int *buff2, int *len2, int *result, int *result_length) {
    int i = 0, j = 0, ost = 0;
    perevor(buff1, len1);
    perevor(buff2, len2);

    if (*len1 > *len2) {
        while (i < *len1 && i < *len2) {
            result[i] += ((10 + buff1[i]) - buff2[i]) % 10;
            if (buff1[i] < buff2[i]) {
                buff1[i + 1] -= 1;
            };
            // printf("%d\n", result[i]);
            i++;
            j++;
        }
        if ((ost) != 0) {
            buff1[*len2] += 1;
        }
        for (i = *len2; i < *len1; i++) {
            result[i] = buff1[i];
            j++;
        }
    }
    if (*len2 > *len1) {
        printf("n/a");
        return;
    }
    if (*len2 == *len1) {
        for (int i = 1; i < *len1; i++) {
            if (buff1[i] < buff2[i]) {
                printf("n/a");
                return;
            }
        }
    }
    *result_length = j;
    perevor(result, result_length);
    output(result, result_length);
    return;
}*/