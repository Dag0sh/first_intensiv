// I WANT TO PLAY WITH YOU
//         YOUR FRIEND, AI
#include <curses.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void read_me();

int main() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, true);
    nodelay(stdscr, true);
    // переносим курсор в начало и очищаем терминал
    int height = 25;
    int length = 80;
    int rocket_position_left = 12;
    int rocket_position_right = 12;
    int ball_x = 41;
    int ball_y = 12;
    int counter_left = 0;
    int counter_right = 0;
    char input;
    int ball_movex, ball_movey;
    ball_movex = 1;
    ball_movey = 1;
    int flag_goal = 1;
    //-----------------------------------------------------------
    //  Генерация поля
    //-----------------------------------------------------------

    while (1) {
        wclear(stdscr);
        for (int i = 0; i < height + 4; i++) {
            for (int j = 0; j < length; j++) {
                if (i == 0 || i == 24 || i == 28) {  // потолок и пол
                    printw("-");
                } else if (i == 26 && j == 20) {  // счетчик левого
                    printw("%d", counter_left);   // подлючить счетчик для левого
                } else if (i == 26 && j == 60) {  // счетчик правого
                    printw("%d", counter_right);  // подлючить счетчик для правого
                } else if ((j == 0 || j == 40 || j == 79) && i <= 24) {  // левая, правая и средняя стенка
                    printw("|");
                } else if (j == ball_x && i == ball_y) {  // положение мяча
                    printw("*");
                } else if (j == 1) {  // левая ракетка
                    if (i == rocket_position_left - 1 || i == rocket_position_left ||
                        i == rocket_position_left + 1) {
                        printw("[");
                    } else {
                        printw(" ");
                    }
                } else if (j == 78) {  // правая ракетка
                    if (i == rocket_position_right - 1 || i == rocket_position_right ||
                        i == rocket_position_right + 1) {
                        printw("]");
                    } else {
                        printw(" ");
                    }
                } else {  // если ничего нет, то просто пробел
                    printw(" ");
                }
            }
            printw("\n");
        }

        read_me();

        // Чтение ввода от пользователя
        char input;
        input = wgetch(stdscr);
        ball_x = ball_x + ball_movex;
        ball_y = ball_y + ball_movey;
        if ((input == 'z') || (input == 'Z')) {
            rocket_position_left++;
            if (rocket_position_left == 23) {
                rocket_position_left--;
            }
        } else if (input == 'a' || input == 'A') {
            rocket_position_left--;
            if (rocket_position_left == 1) {
                rocket_position_left++;
            }
        } else if (input == 'k' || input == 'K') {
            rocket_position_right--;
            if (rocket_position_right == 1) {
                rocket_position_right++;
            }
        } else if (input == 'm' || input == 'M') {
            rocket_position_right++;
            if (rocket_position_right == 23) {
                rocket_position_right--;
            }
        } else if (input == 'h' || input == 'H') {
            return 0;
        }
        // движение мяча
        if ((ball_y == 1) || (ball_y == 23)) {
            ball_movey *= -1;
        }

        if (ball_x == 78 && (rocket_position_right == ball_y || rocket_position_right - 1 == ball_y ||
                             rocket_position_right + 1 == ball_y)) {
            ball_movex *= -1;
        }
        if (ball_x == 2 && (rocket_position_left == ball_y || rocket_position_left - 1 == ball_y ||
                            rocket_position_left + 1 == ball_y)) {
            ball_movex *= -1;
        }
        // ball_x = ball_x + ball_movex;
        // ball_y = ball_y + ball_movey;
        if (ball_x == 79) {
            ++counter_left;
            flag_goal = 1;
            ball_y = 12;
            ball_x = 41;
        }
        if (ball_x == 1) {
            ++counter_right;
            flag_goal = 1;
            ball_y = 12;

            ball_x = 41;
        }

        // проверка на победу
        if (counter_left == 21) {
            wclear(stdscr);
            printf("Left win!\n");
            return 0;
        } else if (counter_right == 21) {
            wclear(stdscr);
            printf("Right win!\n");
            return 0;
        }
        // Задержка для пошагового режима
        napms(200);
    }
    return 0;
}

void read_me() {
    printw("GAME PING-PONG\n");
    printw("Before starting the game, go to full screen mode.\n");
    printw("Control: Left - a/z, Right - k/m, Exit - h:\n");
}
