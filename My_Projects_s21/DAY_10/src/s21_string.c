#include "s21_string.h"

int s21_strlen(const char *str) {
    int s = 0;
    while (*str++) {
        s++;
    }
    return s;
}

int s21_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

char *s21_strcpy(char *copy, const char *str) {
    char *ptr = copy;
    while (*str != '\0') {
        *ptr++ = *str++;
    }
    *ptr = '\0';
    return copy;
}

char *s21_strcat(char *dest, const char *str) {
    char *ptr = dest;
    while (*ptr != '\0') {
        ptr++;
    }
    while (*str != '\0') {
        *ptr = *str;
        ptr++;
        str++;
    }
    *ptr = '\0';
    return dest;
}

char *s21_strchr(const char *str, int a) {
    while (*str != '\0') {
        if (*str == a) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}

char *s21_strstr(const char *str1, const char *str2) {
    if (*str1 == '\0') {
        return (char *)str2;
    }
    while (*str2) {
        const char *bilo = str1;
        const char *stalo = str2;
        while (*bilo && *stalo && *bilo == *stalo) {
            bilo++;
            stalo++;
        }
        if (*stalo == '\0') {
            return (char *)str2;
        }
        str2++;
    }
    return NULL;
}