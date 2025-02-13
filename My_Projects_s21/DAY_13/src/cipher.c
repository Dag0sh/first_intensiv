#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"

#ifdef log
void output(const char *filename, FILE *log_file);
void add(const char *filename, FILE *log_file);
void cesar(const char *filename, int shag, FILE *log_file);
void headout(const char *directory, int shag, FILE *log_file);
void clear_header_files(const char *directory, FILE *log_file);
#elif ci
void output(const char *filename);
void add(const char *filename);
void cesar(const char *filename, int shag);
void headout(const char *directory, int shag);
void clear_header_files(const char *directory);
#endif
int is_alpha(char ch);
int is_low(char ch);

int main() {
    char filename[50];
    char directory[50];
    int mode;
    int shag;
    int flag = 0;
#ifdef log
    FILE *log_file = log_init("logger.log");
    if (log_file == NULL) {
        logcat(log_file, "Неудачная попытка открыть файл", ERROR);
        printf("n/a\n");
        return 1;
    }
    logcat(log_file, "Файл собран", DEBUG);
#endif
    while (flag != 1) {
        if (scanf("%d", &mode) == 1) {
            switch (mode) {
                case 1:
                    scanf(" %49s", filename);
#ifdef log
                    output(filename, log_file);
#elif ci
                    output(filename);
#endif
                    break;
                case 2:
                    scanf(" %49s", filename);
#ifdef log
                    add(filename, log_file);
#elif ci
                    add(filename);
#endif
                    break;
                case 3:
                    scanf(" %s", directory);
                    if (scanf("%d", &shag) == 1) {
#ifdef log
                        headout(directory, shag, log_file);
                        clear_header_files(directory, log_file);
#elif ci
                        headout(directory, shag);
                        clear_header_files(directory);
#endif
                    } else {
#ifdef log
                        logcat(log_file, "Неверное значение сдвига", ERROR);
#endif
                        printf("n/a\n");
                        flag = 1;
                    }
                    break;
                default:
                    flag = 1;
                    if (mode != -1) {
#ifdef log
                        logcat(log_file, "Неверный выбор режима", ERROR);
#endif
                        printf("n/a\n");
                    } else
#ifdef log
                        logcat(log_file, "Файл разобран", DEBUG);
#endif
                    break;
            }
        } else {
            printf("n/a\n");
#ifdef log
            logcat(log_file, "Неверный ввод режима", ERROR);
#endif
            flag = 1;
        }
    }
#ifdef log
    log_close(log_file);
    return 0;
#endif
}
#ifdef log
void output(const char *filename, FILE *log_file)
#elif ci
void output(const char *filename)
#endif
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
#ifdef log
        logcat(log_file, "Неудачная попытка открыть файл", ERROR);
#endif
        printf("n/a\n");
    } else {
#ifdef log
        logcat(log_file, "Файл открылся", INFO);
#endif
        char sign;
        while ((sign = fgetc(file)) != EOF) {
            putchar(sign);
        }
        printf("\n");
        fclose(file);
    }
}

#ifdef log
void add(const char *filename, FILE *log_file)
#elif ci
void add(const char *filename)
#endif
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
#ifdef log
        logcat(log_file, "Неудачная попытка открыть файл для чтения", ERROR);
#endif
        printf("n/a\n");
    }

    else {
        fclose(file);
        file = fopen(filename, "a");
        if (file == NULL) {
#ifdef log
            logcat(log_file, "Неудачная попытка открыть файл для записи", ERROR);
#endif
            printf("n/a\n");
        } else {
            char str[70];
            scanf(" %69s", str);
            fprintf(file, "%s", str);
            fclose(file);
#ifdef log
            logcat(log_file, "Строка добавлена в список", INFO);
            output(filename, log_file);
#elif ci
            output(filename);
#endif
        }
    }
}

int is_alpha(char ch) { return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); }

int is_low(char ch) { return (ch >= 'a' && ch <= 'z'); }

#ifdef log
void cesar(const char *filename, int shag, FILE *log_file)
#elif ci
void cesar(const char *filename, int shag)
#endif
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
#ifdef log
        logcat(log_file, "Неудачная попытка открыть файл для чтения", ERROR);
#endif
        printf("n/a\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *)malloc(length + 1);
    if (content == NULL) {
#ifdef log
        logcat(log_file, "Ошибка выделения памяти", ERROR);
#endif
        printf("n/a\n");
        fclose(file);
        return;
    }

    fread(content, 1, length, file);
    content[length] = '\0';
    fclose(file);

    for (long i = 0; i < length; i++) {
        if (is_alpha(content[i])) {
            int base = is_low(content[i]) ? 'a' : 'A';
            content[i] = (content[i] - base + shag) % 26 + base;
        }
    }

    file = fopen(filename, "w");
    if (file == NULL) {
#ifdef log
        logcat(log_file, "Неудачная попытка открыть файл для записи", ERROR);
#endif
        printf("n/a\n");
        free(content);
        return;
    }
    fwrite(content, 1, length, file);
    fclose(file);
#ifdef log
    logcat(log_file, "Файл успешно зашиврован", INFO);
#endif
    free(content);
}

#ifdef log
void headout(const char *directory, int shag, FILE *log_file)
#elif ci
void headout(const char *directory, int shag)
#endif
{
    DIR *dir = opendir(directory);
    if (dir == NULL) {
#ifdef log
        logcat(log_file, "Неудачная попытка открыть директорию", ERROR);
#endif
        return;
    }

    struct dirent *entry;
    char filepath[1025];

    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".c") != NULL) {
            snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
#ifdef log
            cesar(filepath, shag, log_file);
            logcat(log_file, "Обработаны .с файл", INFO);
#elif ci
            cesar(filepath, shag);
#endif
        }
    }

    closedir(dir);
}

#ifdef log
void clear_header_files(const char *directory, FILE *log_file)
#elif ci
void clear_header_files(const char *directory)
#endif
{
    DIR *dir = opendir(directory);
    if (dir == NULL) {
#ifdef log
        logcat(log_file, "Неудачная попытка открыть директорию", ERROR);
#endif
        printf("n/a\n");
        return;
    }

    struct dirent *entry;
    char filepath[1025];

    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".h") != NULL) {
            snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
            FILE *file = fopen(filepath, "w");
            if (file == NULL) {
#ifdef log
                logcat(log_file, "Не получается открыть файл для очистки", ERROR);
#endif
            } else {
#ifdef log
                logcat(log_file, "Хедер файл очищен", INFO);
#endif
                fclose(file);
            }
        }
    }
    closedir(dir);
}