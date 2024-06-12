#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()
{
	printf("***************************************\n");
	printf("**************  1.play  ***************\n");
	printf("**************  0.exit  ***************\n");
	printf("***************************************\n");
}

void game()
{
	//雷的存放信息

	//布置好的雷的信息
	char mine[ROWS][COLS];

	//排查中的雷的信息
	char show[ROWS][COLS];

	//初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//布置雷
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);

	//扫雷
	FindMine(mine, show, ROW, COL);
}

void test()
{
	int input;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请输入:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n\n");
			break;
		default :
			printf("选择错误，请重选\n\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
