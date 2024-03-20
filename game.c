#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)	//正常运行
{
	int i = 0;
	int j = 0;
	printf("----------扫雷-----------\n");
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);//打印提醒行
	}

	for (i = 1; i <= row; i++)
	{
		printf("\n");
		printf("%d ", i);//打印提醒列
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);//传参的字符打印
		}
	}
	printf("\n----------扫雷-----------\n");
}

//void DisplayBoard(char board[ROW][COL], int row, int col)	//好看但有bug
//{
//	int i;
//	int j;
//	//打印列号
//	for (i = 0; i <= col; i++)
//	{
//		printf("%d|", i);
//	}
//	for (i = 1; i <= row; i++)
//	{
//		printf("\n");
//		printf("--------------------");
//		printf("\n");
//		printf("%d|", i);
//		for (j = 1; j <= col; j++)
//		{
//			printf("%c|", board[i][j]);
//		}
//	}
//}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;//雷数量
	while (count)//直到雷数量为0
	{
		int x = rand() % row + 1;//1-9
		int y = rand() % col + 1;//
		if (board[x][y] == '0')
		{
			board[x][y] = '1';//若为空白0，则填入雷1
			count--;//剩余雷数量减一
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x-1][y] +
		mine[x-1][y-1] +
		mine[x-1][y+1] +
		mine[x][y-1] +
		mine[x][y+1] +
		mine[x+1][y] +
		mine[x+1][y-1] +
		mine[x + 1][y + 1] - 8 * '0');
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < col * row - EASY_COUNT)
	{
		printf("请输入排查雷的坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//合法
			//判断是不是雷
			if (mine[x][y] == '1')//是雷
			{
				printf("很遗憾，你失败了\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else//不是雷
			{
				//判断该点位周围有几个雷
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("坐标错误，请重新输入!\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜，你胜利了^.^\n");
		DisplayBoard(mine, ROW, COL);
	}
}
