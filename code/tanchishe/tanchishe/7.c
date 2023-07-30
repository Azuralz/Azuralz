#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROW 20
#define COL 20
#define INIT_LENGTH 5
#define MAX_LENGTH 50
#define SPEED 150

int score = 0;
char map[ROW][COL];
int head_x, head_y;
int food_x, food_y;
int length;
int x[100], y[100];

void createMap() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1) {
                map[i][j] = '*';
            }
            else {
                map[i][j] = ' ';
            }
        }
    }
}

void initSnake() {
    length = INIT_LENGTH;
    head_x = ROW / 2;
    head_y = COL / 2;

    for (int i = 0; i < length; i++) {
        x[i] = head_x;
        y[i] = head_y + i;
        map[x[i]][y[i]] = '*';
    }
}

void createFood() {
    while (1) {
        food_x = rand() % (ROW - 2) + 1;
        food_y = rand() % (COL - 2) + 1;
        if (map[food_x][food_y] == ' ') {
            map[food_x][food_y] = '$';
            break;
        }
    }
}

void showMap() {
    system("cls");

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

void updatePos() {
    int temp_x = x[0];
    int temp_y = y[0];
    x[0] = head_x;
    y[0] = head_y;
    map[x[0]][y[0]] = '*';

    for (int i = 1; i < length; i++) {
        int p = x[i];
        int q = y[i];
        x[i] = temp_x;
        y[i] = temp_y;
        map[x[i]][y[i]] = '*';
        temp_x = p;
        temp_y = q;
    }
}

void gameOver() {
    system("cls");
    printf("Game over!\n");
    printf("Your score: %d\n", score);
    getch();
    exit(0);
}

int main() {
    srand(time(NULL));
    createMap();
    initSnake();
    createFood();
    showMap();

    while (1) {
        Sleep(SPEED);

        if (kbhit()) {
            int key = getch();
            if (key == 224) {
                key = getch();
            }
            switch (key) {
            case 72:
                head_x--;
                break;
            case 75:
                head_y--;
                break;
            case 77:
                head_y++;
                break;
            case 80:
                head_x++;
                break;
            default:
                break;
            }
        }

        if (head_x == 0 || head_x == ROW - 1 || head_y == 0 || head_y == COL - 1) {
            gameOver();
        }

        if (map[head_x][head_y] == '*' || length >= MAX_LENGTH) {
            gameOver();
        }

        if (map[head_x][head_y] == '$') {
            score++;
            length++;
            createFood();
        }
        else {
            map[x[length - 1]][y[length - 1]] = ' ';
        }

        updatePos();
        showMap();
    }
    return 0;
}