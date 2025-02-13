#include <curses.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LINE 25
#define COLOMN 80

void input_arr(int arr[LINE][COLOMN]);
void update_arr(int arr1[LINE][COLOMN], int arr2[LINE][COLOMN]);
int sosed(int arr[LINE][COLOMN], int i, int j);
int solv(int sosed, int now);
void replace(int arr1[LINE][COLOMN], int arr2[LINE][COLOMN]);
int count(int arr[LINE][COLOMN]);
int speed(char press, int *out, int time);

int main() {
    int arr1[LINE][COLOMN];
    int arr2[LINE][COLOMN];
    int time = 100000;
    int out = 0;

    input_arr(arr1);
    if (freopen("/dev/tty", "r", stdin)) {
        initscr();
        nodelay(stdscr, true);
        cbreak();
        noecho();
        curs_set(0);
    }
    while (out != 1) {
        char press = getch();
        if (count(arr1) == 0) {
            out = 1;
        }
        time = speed(press, &out, time);
        usleep(time);
        clear();
        update_arr(arr1, arr2);
        refresh();
        replace(arr1, arr2);
    }
    endwin();
    return 0;
}

void input_arr(int arr[LINE][COLOMN]) {
    for (int i = 0; i < LINE; i++) {
        for (int j = 0; j < COLOMN; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void update_arr(int arr1[LINE][COLOMN], int arr2[LINE][COLOMN]) {
    for (int i = 0; i < LINE; i++) {
        for (int j = 0; j < COLOMN; j++) {
            arr2[i][j] = solv(sosed(arr1, i, j), arr1[i][j]);  // добавить функцию принятия решений
            if (arr2[i][j] == 1)
                printw("+");
            else
                printw(".");
        }
        printw("\n");
    }
}

int sosed(int arr[LINE][COLOMN], int i, int j) {
    int sum = 0;
    int id = i - 1, jl = j - 1, iu = i + 1, jr = j + 1;
    if (id < 0) {
        id = LINE - 1;
    }
    if (jl < 0) {
        jl = COLOMN - 1;
    }
    if (iu > LINE - 1) {
        iu = 0;
    }
    if (jr > COLOMN - 1) {
        jr = 0;
    }
    sum += arr[iu][jl];
    sum += arr[iu][j];
    sum += arr[iu][jr];
    sum += arr[i][jl];
    sum += arr[i][jr];
    sum += arr[id][jr];
    sum += arr[id][j];
    sum += arr[id][jl];
    return sum;
}

int solv(int sosed, int now) {
    int gen;
    if ((sosed == 2 || sosed == 3) && now == 1) {
        gen = 1;
    } else if (sosed == 3 && now == 0) {
        gen = 1;
    } else
        gen = 0;
    return gen;
}

int count(int arr[LINE][COLOMN]) {
    int sum = 0;
    for (int i = 0; i < LINE; i++) {
        for (int j = 0; j < COLOMN; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

int speed(char press, int *out, int time) {
    switch (press) {
        case 'w':
            time += 10000;
            break;
        case 's':
            time -= 10000;
            break;
        case 'h':
            *out = 1;
            break;
        default:
            break;
    }
    return time;
}

void replace(int arr1[LINE][COLOMN], int arr2[LINE][COLOMN]) {
    for (int i = 0; i < LINE; i++) {
        for (int j = 0; j < COLOMN; j++) {
            arr1[i][j] = arr2[i][j];
        }
    }
}
