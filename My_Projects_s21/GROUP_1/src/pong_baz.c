// I WANT TO PLAY WITH YOU
//         YOUR FRIEND, AI
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void read_me();

int main() {
    // переносим курсор в начало и очищаем терминал
    srand(time(NULL));
    int x, y;
    y = 1 + rand() % 23;
    int height = 25;
    int length = 80;
    int rocket_position_left = 12;
    int rocket_position_right = 12;
    int ball_x = 41;
    int ball_y = y;
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
        printf("\033[H\033[J");
        for (int i = 0; i < height + 4; i++) {
            for (int j = 0; j < length; j++) {
                if (i == 0 || i == 24 || i == 28) {  // потолок и пол
                    printf("-");
                } else if (i == 26 && j == 20) {  // счетчик левого
                    printf("%d", counter_left);   // подлючить счетчик для левого
                } else if (i == 26 && j == 60) {  // счетчик правого
                    printf("%d", counter_right);  // подлючить счетчик для правого
                } else if ((j == 0 || j == 40 || j == 79) && i <= 24) {  // левая, правая и средняя стенка
                    printf("|");
                } else if (j == ball_x && i == ball_y) {  // положение мяча
                    printf("*");
                } else if (j == 1) {  // левая ракетка
                    if (i == rocket_position_left - 1 || i == rocket_position_left ||
                        i == rocket_position_left + 1) {
                        printf("[");
                    } else {
                        printf(" ");
                    }
                } else if (j == 78) {  // правая ракетка
                    if (i == rocket_position_right - 1 || i == rocket_position_right ||
                        i == rocket_position_right + 1) {
                        printf("]");
                    } else {
                        printf(" ");
                    }
                } else {  // если ничего нет, то просто пробел
                    printf(" ");
                }
            }
            printf("\n");
        }

        read_me();

        // Чтение ввода от пользователя
        char input;
        scanf("%c", &input);
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
        } else if (input != ' ') {
            continue;
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
        ball_x = ball_x + ball_movex;
        ball_y = ball_y + ball_movey;
        if (ball_x == 79) {
            ++counter_left;
            flag_goal = 1;
            ball_y = 1 + rand() % 23;
            ball_x = 41;
        }
        if (ball_x == 1) {
            ++counter_right;
            flag_goal = 1;
            ball_y = 1 + rand() % 23;

            ball_x = 41;
        }

        // проверка на победу
        if (counter_left == 21) {
            printf("\033[H\033[J");
            printf("Left win!\n");
            return 0;
        } else if (counter_right == 21) {
            printf("\033[H\033[J");
            printf("Right win!\n");
            return 0;
        }
        // Задержка для пошагового режима
        usleep(100000);  // задержка в микросекундах (100 миллисекунд)
    }
    return 0;
}

void read_me() {
    printf("GAME PING-PONG\n");
    printf("Before starting the game, go to full screen mode.\n");
    printf("Control: Left - a/z, Right - k/m, Exit - h:\n");
}
