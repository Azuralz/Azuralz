#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<windows.h>
#include <synchapi.h>
#define ROWS 11
#define COLS 11
#define ROW 9
#define COL 9
#define easy_mine 10
int record = 0;
void display(char board[ROWS][COLS], int row, int col)//��ӡ���̣���ʲô��ӡʲô
{
    int i = 0;
    int j = 0;
    for (j = 0; j < col + 1; j++)
    {
        printf("   %d", j);
    }
    printf("\n");
    printf("\n");
    for (i = 1; i < row + 1; i++)
    {
        printf("   %d", i);
        for (j = 1; j < col + 1; j++)
        {
            printf("   %c", board[i][j]);
        }
        printf("\n");
        printf("\n\n");
    }
}
int count_mine(char mine[ROWS][COLS], int i, int j)//�������Լ����ڵľŸ����ӵ�����
{
    int a = 0;
    int b = 0;
    int count = 0;
    for (a = i - 1; a <= i + 1; a++)
    {
        for (b = j - 1; b <= j + 1; b++)
        {
            // if(a> 0 && b > 0 && a < ROW + 1 && b < COL + 1)
            count = mine[a][b] - '0' + count;//'1'-'0'=1;
        }
    }
    return count;
}
void expendboard(char mine[ROWS][COLS], char show[ROWS][COLS], int i, int j)//���пհ�չ��
{
    int a = 0;
    int b = 0;
    int count = count_mine(mine, i, j);
    if (count == 0)
    {
        show[i][j] = ' ';
        for (a = i - 1; a <= i + 1; a++)
        {
            for (b = j - 1; b <= j + 1; b++)
            {
                if (a > 0 && b > 0 && a < ROW + 1 && b < COL + 1 && show[a][b] == '?' && (mine[a][b] != '1' || show[a][b] == '*'))
                    expendboard(mine, show, a, b);//�ݹ飺����չ��
            }
        }
    }
    else
    {
        show[i][j] = count + '0';   //��ʾ����

    }
}
int search_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//����
{
    int i = 0;
    int j = 0;
    int win = 0;
    int input = 0;
    int mark = 0;
    int step = 0;
    while (win < easy_mine)//����ٽ�ֵ
    {
        printf("********************\n");
        printf("******* 1.��� *****\n");
        printf("******* 2.�鿴 *****\n");
        printf("********************\n");
        printf("\n\t\t\t\t\t�ѱ��:%d\n", win);//��ʾ��Ǹ���
        printf("\n\t\t\t\t\t���ײ���:%d\n", step);//����
        printf("��ѡ��:>");
        scanf_s("%d", &input);
        switch (input)
        {

        case 1:
            printf("ѡ��Ҫ��ǵĵؿ����꣨�ٴα�Ǻ�ȡ����:>");
            scanf_s("%d %d", &i, &j);
            if (show[i][j] == '?' && mark <= easy_mine)
            {
                show[i][j] = '*';
                mark++;
                if (mine[i][j] == '1')
                    win++;
                system("cls");//�����һ��              
                display(show, ROW, COL);
            }
            else if (mark > 10)
                printf("�����������ȡ��\n");
            else if (show[i][j] == '*')
            {
                show[i][j] = '?';
                mark--;
                if (mine[i][j] == '1')//��ȷ����
                    win--;
                display(show, ROW, COL);
            }
            break;
        case 2:
            while (1)
            {
                step++;
                printf("ѡ��Ҫ�鿴�ĵؿ�����:>");
                scanf_s("%d %d", &i, &j);
                if (step == 1 && show[i][j] == '?' && mine[i][j] == '1')
                {
                    mine[i][j] = '0';
                    while (1)
                    {
                        int a = rand() % 9 + 1;
                        int b = rand() % 9 + 1;
                        if ((a != i || b != j) && mine[a][b] == '0')
                        {
                            mine[a][b] = '1';
                            break;
                        }
                    }
                }
                if (show[i][j] == '?' && mine[i][j] == '0')
                {
                    expendboard(mine, show, i, j);
                    system("cls");//�����һ��
                    display(show, ROW, COL);
                    break;
                }
                else if (show[i][j] == '?' && mine[i][j] == '1')
                {
                    step++;
                    system("cls");
                    printf("���ź����㱻ը����\n");
                    printf("��������\n");
                    display(mine, ROW, COL);
                    printf("\n\t\t\t���ײ���:%d\n", step);//����
                    break;
                }
                else if (show[i][j] != '?')
                    printf("����Ƿ���������\n");
            }
            break;
        default:
            system("cls");
            display(show, ROW, COL);
            printf("����Ƿ���������\n");
            break;
        }
        if (mine[i][j] == '1' && input == 2)
            break;
        if (win == easy_mine || step == col * row - easy_mine)
        {
            system("cls");
            display(show, ROW, COL);//չʾ�ɹ�
            printf("���׳ɹ�\n");
            printf("\n\t\t\t���ײ���:%d\n", step);//����
            if ((record != 0 && record > step) || record == 0)
                record = step;
            system("pause");
            break;
        }
    }
    return 1;
}
void setmine(char board[ROWS][COLS], int row, int col)//����
{
    int count = easy_mine;
    while (count > 0)
    {
        int i = rand() % 9 + 1;
        int j = rand() % 9 + 1;
        if (board[i][j] == '0')
        {
            count--;
            board[i][j] = '1';
        }


    }
}
void initboard(char board[ROWS][COLS], int row, int col, char set)//��ʼ��show���̺�mine���̣�set����ʲô��ӡʲô
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row + 2; i++)
    {
        for (j = 0; j < col + 2; j++)
        {
            board[i][j] = set;
        }
    }
}
void game()
{
    char board1[ROWS][COLS] = { 0 };
    char board2[ROWS][COLS] = { 0 };
    initboard(board1, ROW, COL, '0');//mine
    initboard(board2, ROW, COL, '?');//show
    display(board2, ROW, COL);
    setmine(board1, ROW, COL);
    display(board1, ROW, COL);//����debug
    while (1)
    {
        int p = search_mine(board1, board2, ROW, COL);
        if (p == 1)
            break;
    }

}
void menu()
{
    printf("*******************************\n");
    printf("*****  1. play  0. exit   *****\n");
    printf("*******************************\n");
}
void text()
{
    int input = 0;
    do
    {
        printf("\n\t\t\tɨ��\n");
        printf("\t\t\t\t\t��ü�¼:%d\n", record);
        menu();
        printf("��ѡ��:>");
        scanf_s("%d", &input);
        system("cls");
        switch (input)
        {
        case 1:
            printf("��Ϸ��ʼ\n");
            game();
            Sleep(1000);
            system("cls");
            break;
        case 0:
            printf("�˳���Ϸ\n");
            break;
        default:
            printf("����Ƿ��������䣡\n");
            break;
        }

    } while (input);
}
int main()
{
    srand((unsigned int)time(NULL));//������ʱ�����õ����������
    text();
}