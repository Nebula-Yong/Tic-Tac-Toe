#include <graphics.h>//图形库头文件
#include<stdio.h>
#include<math.h>
#include<mmsystem.h>
#include "task.h"//井字棋头文件

void huamian()          //画出棋盘
{
	initgraph(800, 800);//创建图形窗口大小
	setcolor(BLACK);
	for (int i = 150;i <= 450;i += 100) {
		line(i, 150, i, 450);
	}
	for (int i = 150;i <= 450;i += 100) {
		line(150, i, 450, i);
	}
	IMAGE img;	//准备图片
	loadimage(NULL,"背景.jpg",800,800); //打开图片
	
	
	for (int i = 150;i <= 450;i += 100) { //划线
		line(i, 150, i, 450);
	}
	for (int i = 150;i <= 450;i += 100) {
		line(150, i, 450, i);
	}
}

void huamian1()          //不用再建立窗口，重置棋盘
{
	IMAGE img;	//准备图片
	loadimage(NULL, "背景.jpg", 800, 800);
	setcolor(BLACK);//线条黑色
	for (int i = 150;i <= 450;i += 100) {
		line(i, 150, i, 450);
	}
	for (int i = 150;i <= 450;i += 100) {
		line(150, i, 450, i);
	}
}

void isCircle(int i,int j) //画圆
{
	int x = (i+2)*100;
	int y = (j + 2) * 100;
	setfillcolor(BLUE);
	solidcircle(x, y, 30);
}

void isCha(int i, int j)//画叉
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

void playChess()//下棋过程
{
	MOUSEMSG m;//保存鼠标信息
	
	while (1)
	{
		
		int i, j,flag=0;
		m = GetMouseMsg();//获取一个鼠标信息
		int x, y,x1,y1,x2,y2;
		for (int i = 2;i < 5;i++) {
			for (int j = 2;j < 5;j++) {
				if (abs(m.x - i * 100) < 50 && abs(m.y - j * 100) < 50) {
					x = i * 100;
					y = j * 100;
				}
			}
		}
		
		if (m.uMsg == WM_LBUTTONDOWN) {//如果鼠标左键单击，处理鼠标的坐标成棋盘坐标
			
			x = 0.01 * x - 2;
			y = 0.01 * y - 2;
			if (chessBoard[0][y][x] == 1) {//先判断这个地方是否有子，已经有子了就不能下了
				continue;//以防重复点击相同位置
			}
			else {
				
				task1(x, y);//把坐标给task函数处理
				clearrectangle(0, 0, 800, 800);//清除画面
				huamian1();//重新画棋盘
				for (int i = 0;i < 3;i++) {//遍历棋盘的每一个位置
					for (int j = 0;j < 3;j++) {
						if (chessBoard[0][i][j] == 1) {//task返回给我三维数组，第0层代表是否有子
							if (chessBoard[1][i][j] == 0) {//第一层代表是圆还是叉
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
	
	while (1);//防止闪退
	
	
	return 0;
}
