#include <graphics.h>//ͼ�ο�ͷ�ļ�
#include<stdio.h>
#include<math.h>
#include<mmsystem.h>
#include "task.h"//������ͷ�ļ�

void huamian()          //��������
{
	initgraph(800, 800);//����ͼ�δ��ڴ�С
	setcolor(BLACK);
	for (int i = 150;i <= 450;i += 100) {
		line(i, 150, i, 450);
	}
	for (int i = 150;i <= 450;i += 100) {
		line(150, i, 450, i);
	}
	IMAGE img;	//׼��ͼƬ
	loadimage(NULL,"����.jpg",800,800); //��ͼƬ
	
	
	for (int i = 150;i <= 450;i += 100) { //����
		line(i, 150, i, 450);
	}
	for (int i = 150;i <= 450;i += 100) {
		line(150, i, 450, i);
	}
}

void huamian1()          //�����ٽ������ڣ���������
{
	IMAGE img;	//׼��ͼƬ
	loadimage(NULL, "����.jpg", 800, 800);
	setcolor(BLACK);//������ɫ
	for (int i = 150;i <= 450;i += 100) {
		line(i, 150, i, 450);
	}
	for (int i = 150;i <= 450;i += 100) {
		line(150, i, 450, i);
	}
}

void isCircle(int i,int j) //��Բ
{
	int x = (i+2)*100;
	int y = (j + 2) * 100;
	setfillcolor(BLUE);
	solidcircle(x, y, 30);
}

void isCha(int i, int j)//����
{
	int x1, y1, x2, y2;
	int x = (i + 2) * 100;
	int y = (j + 2) * 100;
	setcolor(RED);
	x1 = x - 30;
	y1 = y - 30;
	x2 = x + 30;
	y2 = y + 30;
	line(x1, y1, x2, y2);
	line(x2, y1, x1, y2);
}

void playChess()//�������
{
	MOUSEMSG m;//���������Ϣ
	
	while (1)
	{
		
		int i, j,flag=0;
		m = GetMouseMsg();//��ȡһ�������Ϣ
		int x, y,x1,y1,x2,y2;
		for (int i = 2;i < 5;i++) {
			for (int j = 2;j < 5;j++) {
				if (abs(m.x - i * 100) < 50 && abs(m.y - j * 100) < 50) {
					x = i * 100;
					y = j * 100;
				}
			}
		}
		
		if (m.uMsg == WM_LBUTTONDOWN) {//������������������������������������
			
			x = 0.01 * x - 2;
			y = 0.01 * y - 2;
			if (chessBoard[0][y][x] == 1) {//���ж�����ط��Ƿ����ӣ��Ѿ������˾Ͳ�������
				continue;//�Է��ظ������ͬλ��
			}
			else {
				
				task1(x, y);//�������task��������
				clearrectangle(0, 0, 800, 800);//�������
				huamian1();//���»�����
				for (int i = 0;i < 3;i++) {//�������̵�ÿһ��λ��
					for (int j = 0;j < 3;j++) {
						if (chessBoard[0][i][j] == 1) {//task���ظ�����ά���飬��0������Ƿ�����
							if (chessBoard[1][i][j] == 0) {//��һ�������Բ���ǲ�
								isCircle(j, i);
							}
							else if (chessBoard[1][i][j] == 1) {
								isCha(j, i);
							}
						}
					}
				}
			}	
		}
	}
}

int main()
{
	huamian();
	playChess();
	
	while (1);//��ֹ����
	
	
	return 0;
}
