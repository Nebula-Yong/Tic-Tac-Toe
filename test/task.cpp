#include "task.h"
//#include <stdio.h>
int chessBoard[3][3][3] ; //���ԣ�0���Ƿ������ӣ�1��(O)��(X)�ӣ�2���ڼ����µ�)��y��x
static int count = 0;           //���ڼ�����static��ʾcount����������Ϊ��ǰĿ¼��
void task1(int x, int y)
{
    chessBoard[0][y][x] = 1;
    if (count % 2 == 0)
    {
        chessBoard[1][y][x] = 0; // 0������� (O)
    }
    else
    {
        chessBoard[1][y][x] = 1; // 1������ӣ�X)
    }
    count++;
    addDepth();//�������  ����ȴ������Ӵ��ڵĻغ���
    clearChess(); //�������
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
            if (chessBoard[0][i][j] == 1) //�������
            {
                chessBoard[2][i][j] ++;//�������1
            }

        }

    }

}
void clearChess() {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (chessBoard[2][i][j] == 7)//���һ�����Ӵ���7���غ�������
            {
                chessBoard[2][i][j] = 0;//�������
                chessBoard[0][i][j] = 0;//��λ��û������
            }

        }

    }
}
void output() {  //������
    //printf("����:\n");
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
    //printf("���\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //printf("%d ", chessBoard[2][i][j]);
        }
        //printf("\n");
    }
}