/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

int input(int *buffer, int *length);
void output(int *buffer, int *length);
int sum_numbers(int *buffer, int *length);
int find_numbers(int *buffer, int *length, int *new, int *numb);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n, buffer[10], new[10], numb;
    if (input(buffer, &n) == 1) {
        printf("n/a");
        return 0;
    }
    sum_numbers(buffer, &n);
    find_numbers(buffer, &n, new, &numb);
    if (find_numbers(buffer, &n, new, &numb) == 1) {
        printf("n/a");
        return 0;
    }
    output(new, &numb);
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n < 1 || *n > 10) {
        return 1;
    }
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }
    return 0;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int *length) {
    int sum = 0;
    for (int i = 0; i < *length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

void output(int *a, int *n) {
    printf("%d\n", sum_numbers(a, n));

    for (int i = 0; i < *n; i++) {
        if (i == *n - 1) {
            printf("%d", a[i]);
        } else
            printf("%d ", a[i]);
    }
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int *n, int *new, int *numb) {
    int j = 0;
    int sum = sum_numbers(buffer, n);
    if (sum == 0) {
        return 1;
    }
    for (int i = 0; i < *n; i++) {
        if (buffer[i] != 0) {
            if (sum % buffer[i] == 0) {
                new[j] = buffer[i];
                j++;
            }
        }
    }
    *numb = j;
    return 0;
}
