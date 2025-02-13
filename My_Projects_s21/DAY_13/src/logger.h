#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

typedef enum { DEBUG, INFO, WARNING, ERROR } log_level;

FILE* log_init(const char* filename);
int logcat(FILE* log_file, const char* message, log_level level);
int log_close(FILE* log_file);

#endif