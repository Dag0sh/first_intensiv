#ifndef STRLEN_H
#define STRLEN_H
#include <stdio.h>

int s21_strlen(const char *str);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strcpy(char *copy, const char *str);
char *s21_strcat(char *dest, const char *str);
char *s21_strchr(const char *str, int a);
char *s21_strstr(const char *str1, const char *str2);

#endif