#include "logger.h"

#include <stdarg.h>
#include <string.h>
#include <time.h>

#define TIMESTAMP_SIZE 20
#define LOG_MESSAGE_SIZE 256

static const char* log_level_str[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

FILE* log_init(const char* filename) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        return NULL;
    }
    return file;
}

int logcat(FILE* log_file, const char* message, log_level level) {
    if (log_file == NULL) {
        return -1;
    }

    char timestamp[TIMESTAMP_SIZE];
    char log_message[LOG_MESSAGE_SIZE];
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);

    strftime(timestamp, TIMESTAMP_SIZE, "%Y-%m-%d %H:%M:%S", tm_info);

    snprintf(log_message, LOG_MESSAGE_SIZE, "[%s] [%s] %s\n", timestamp, log_level_str[level], message);

    return fputs(log_message, log_file) != EOF ? 0 : -1;
}

int log_close(FILE* log_file) {
    if (log_file == NULL) {
        return -1;
    }
    return fclose(log_file);
}