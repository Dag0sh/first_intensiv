#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

struct door {
    int id;
    int status;
};