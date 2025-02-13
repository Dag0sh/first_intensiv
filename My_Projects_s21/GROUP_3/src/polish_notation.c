#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

double f3(double a) { return (double)(sin(cos(2 * a))); }

int is_number(const char *str) {
    if (*str == '-' || *str == '+') {
        str++;
    }
    int has_digit = 0;
    int has_decimal = 0;
    while (*str) {
        if (*str == '.') {
            if (has_decimal) return 0;
            has_decimal = 1;
        } else if (*str < '0' || *str > '9') {
            return 0;
        } else {
            has_digit = 1;
        }
        str++;
    }
    return has_digit;
}

int main() {
    struct stack *st = NULL;
    char *array = inputString();
    char *postfix = malloc(sizeof(char));
    postfix[0] = '\0';
    int len_postfix = 0;
    double x;
    if (array == NULL) {
        return 1;
    }

    char *token = strtok(array, " ");
    while (token != NULL) {
        if (is_number(&token[0])) {
            double number = atof(token);
            char numberStr[32];
            if (number == (int)number) {
                snprintf(numberStr, sizeof(numberStr), "%d", (int)number);
            } else {
                snprintf(numberStr, sizeof(numberStr), "%.2f", number);
            }
            // int postfixLength = strlen(postfix);
            strncat(postfix, numberStr, sizeof(numberStr) - 1);
            len_postfix += strlen(numberStr);
            postfix = realloc(postfix, len_postfix * sizeof(char));

        } else if (token[0] == '(') {
            push(&st, token[0]);
        } else if (token[0] == ')') {
            while ((x = pop(&st)) != '(' && !isEmpty(st)) {
                printf("%f", x);
            }
            if (isEmpty(st) || x != '(') {
                free(array);
                destroy(&st);
                return 1;
            }
        } else {
            while (!isEmpty(st) && priority(st->num) >= priority(token[0])) {
                postfix[len_postfix] = pop(&st);
                len_postfix++;
                postfix = realloc(postfix, len_postfix * sizeof(char));
            }
            push(&st, token[0]);
        }
        token = strtok(NULL, " ");
    }
    while (!isEmpty(st)) {
        postfix[len_postfix] = pop(&st);
        len_postfix++;
        postfix = realloc(postfix, len_postfix * sizeof(char));
    }
    printf("%s", postfix);

    printf("\n");

    double a = 0;
    double y3min = -1;
    double y3max = 1;
    double step3 = (y3max - y3min) / 25.0;
    for (int j = 1; j <= 25; j++) {
        for (int i = 1; i <= 80; i++) {
            a = ((4.0 * M_PI) / 80.0) * (double)(i - 1);
            double func = 0.0;
            func = f3(a);
            double y_step_min = y3min + step3 * (j - 1);
            double y_step_max = y3min + step3 * j;
            if (func <= y_step_max && func >= y_step_min) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;

    free(array);
    free(postfix);
    destroy(&st);
    return 0;
}
