#include "task.h"
//#include <stdio.h>
int chessBoard[3][3][3] ; //属性（0：是否有棋子，1：(O)或(X)子，2；第几次下的)，y，x
static int count = 0;           //用于计数，static表示count变量作用域为当前目录，
void task1(int x, int y)
{
    chessBoard[0][y][x] = 1;
    if (count % 2 == 0)
    {
        chessBoard[1][y][x] = 0; // 0代表黑子 (O)
    }
    else
    {
        chessBoard[1][y][x] = 1; // 1代表白子（X)
    }
    count++;
    addDepth();//增加深度  ，深度代表棋子存在的回合数
    clearChess(); //清理深度
    //output();
    // printf("%d\n", count);
    // printf("%d",chessBoard[0][y][x]);
}
void addDepth()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (chessBoard[0][i][j] == 1) //如果有子
            {
                chessBoard[2][i][j] ++;//深度增加1
            }

        }

    }

}
void clearChess() {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (chessBoard[2][i][j] == 7)//如果一颗棋子存在7个回合则清零
            {
                chessBoard[2][i][j] = 0;//深度清零
                chessBoard[0][i][j] = 0;//该位置没有棋子
            }

        }

    }
}
void output() {  //测试用
    //printf("棋盘:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (chessBoard[0][i][j] == 1)
            {
                if (chessBoard[1][i][j] == 0)
                {
                    //printf("O ");
                }
                else {
                    //printf("X ");
                }


            }
            else {
                //printf("- ");
            }

        }
        //printf("\n");
    }
    //printf("深度\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //printf("%d ", chessBoard[2][i][j]);
        }
        //printf("\n");
    }
}