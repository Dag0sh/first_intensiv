#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

char *inputString() {
    char *arr;
    int size = 0;
    int capacity = 1;
    char ch;
    arr = (char *)malloc(capacity * sizeof(char));
    if (arr == NULL) {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }
    while (scanf("%c", &ch) == 1 && ch != '\n') {
        if (size == capacity) {
            capacity *= 2;
            char *temp = realloc(arr, capacity * sizeof(char));
            if (temp == NULL) {
                free(arr);
                printf("Ошибка выделения памяти\n");
                return NULL;
            }
            arr = temp;
        }
        arr[size++] = ch;
    }
    if (size == capacity) {
        char *temp = realloc(arr, (capacity + 1) * sizeof(char));
        if (temp == NULL) {
            free(arr);
            printf("Ошибка выделения памяти\n");
            return NULL;
        }
        arr = temp;
    }
    arr[size] = '\0';
    return arr;
}

struct stack *init(int num) {
    struct stack *ret = (struct stack *)malloc(sizeof(struct stack));
    if (ret == NULL) {
        printf("stack.c: Memmory allocation error!.. ");
        return NULL;
    }
    ret->next = NULL;
    ret->num = num;
    return ret;
}

void push(struct stack **last, char ch) {
    struct stack *ret = (struct stack *)malloc(sizeof(struct stack));
    if (ret == NULL) {
        printf("Ошибка выделения памяти в push");
        exit(1);
    }
    ret->next = *last;
    ret->num = ch;
    *last = ret;
}

char pop(struct stack **last) {
    struct stack *ptr;
    char ch;

    if (*last == NULL) {
        printf("stack.c: Stack UNDERflow error!.. ");
        exit(1);
    }
    ptr = (*last)->next;
    ch = (*last)->num;
    free(*last);
    *last = ptr;
    return (ch);
}

void destroy(struct stack **last) {
    struct stack *ret = *last;
    while (ret) {
        struct stack *temp = ret->next;
        free(ret);
        ret = temp;
    }
    *last = NULL;
}

int priority(char x) {
    switch (x) {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

int isEmpty(struct stack *st) { return st == NULL; }