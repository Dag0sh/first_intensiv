#include "s21_string.h"

void s21_strlen_test(const char *str);
void s21_strcmp_test(const char *str1, const char *str2);
void s21_strspy_test(char *str1, const char *str2);
void s21_strcat_test(char *dest, const char *str);
void s21_strchr_test(const char *str, int a);
void s21_strstr_test(const char *str1, const char *str2);

int main() {
#ifdef LENTEST
    const char *str1 = "hello world!";
    s21_strlen_test(str1);
    const char *str2 = "";
    s21_strlen_test(str2);
    const char *str3 = "$#@^&!";
    s21_strlen_test(str3);
#elif cmptest
    const char *str1 = "tytafurt";
    const char *str2 = "tytatyta";
    s21_strcmp_test(str1, str2);
    const char *str3 = "12342424";
    const char *str4 = "11111111";
    s21_strcmp_test(str3, str4);
    const char *str5 = "";
    const char *str6 = "";
    s21_strcmp_test(str5, str6);
#elif cpytest
    const char *str1 = "";
    char copy1[50];
    s21_strspy_test(copy1, str1);
    const char *str2 = " ";
    char copy2[50];
    s21_strspy_test(copy2, str2);
    const char *str3 = "tytafurt";
    char copy3[50];
    s21_strspy_test(copy3, str3);
#elif cattest
    const char *str1 = "";
    char copy1;
    s21_strcat_test(&copy1, str1);
    const char *str2 = " ";
    char copy2;
    s21_strcat_test(&copy2, str2);
    const char *str3 = "tytafurt";
    char copy3;
    s21_strcat_test(&copy3, str3);
#elif chrtest
    const char *str1 = "123";
    char a1 = '3';
    s21_strchr_test(str1, a1);
    const char *str2 = "133332";
    char a2 = '2';
    s21_strchr_test(str2, a2);
    const char *str3 = "2342342";
    char a3 = '1';
    s21_strchr_test(str3, a3);
#elif strtest
    const char *str1 = "12345";
    const char *str2 = "123";
    s21_strstr_test(str1, str2);
    const char *str3 = "";
    const char *str4 = "123";
    s21_strstr_test(str3, str4);
    const char *str5 = "123";
    const char *str6 = "123";
    s21_strstr_test(str5, str6);
#endif
    return 0;
}

void s21_strlen_test(const char *str) { printf("'%s', %d, SUCCESS\n", str, s21_strlen(str)); }
void s21_strcmp_test(const char *str1, const char *str2) {
    printf("'%s', '%s', '%d' SUCCESS\n", str1, str2, s21_strcmp(str1, str2));
}
void s21_strspy_test(char *str1, const char *str2) {
    printf("'%s', '%s' SUCCESS\n", str1, s21_strcpy(str1, str2));
}
void s21_strcat_test(char *dest, const char *str) {
    printf("'%s', '%s' SUCCESS\n", str, s21_strcat(dest, str));
}
void s21_strchr_test(const char *str, int a) { printf("'%s', '%s' SUCCESS\n", str, s21_strchr(str, a)); }
void s21_strstr_test(const char *str1, const char *str2) {
    printf("'%s', '%s' SUCCESS\n", str1, s21_strstr(str1, str2));
}
