#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char* message) {
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%H:%M:%S", tm_info);
    for (char* p = Log_prefix; *p; p++) {
        print(*p);
    }
    print(' ');
    for (char* p = timestamp; *p; p++) {
        print(*p);
    }
    print(' ');
    for (char* p = message; *p; p++) {
        print(*p);
    }
}