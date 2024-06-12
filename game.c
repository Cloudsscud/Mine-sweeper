#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

//初始化面板
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

//显示面板
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

//设置雷图
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

//找出所排查的坐标的3x3区域有多少雷
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

////将所排查为空的这一点周围3x3区域显示出来，并返回其展开的数量
//int Show_Together(char show[ROWS][COLS], char mine[ROWS][COLS], int x, int y)
//{
//	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)//判断点位是否合法
//	{
//		//排查数量
//		int win = 0,
//			win_up = 0,
//			win_down = 0,
//			win_left = 0,
//			win_right = 0,
//			win_leftup = 0,
//			win_leftdown = 0,
//			win_rightup = 0,
//			win_rightdown = 0;
//
//		//周围八格的雷数量
//		int count;
//		//上
//		if ((count = get_mine_count(mine, x - 1, y)) == 0)
//		{
//			show[x-1][y] = '0';
//			win_up = Show_Together(show, mine, x - 1, y) + 1;
//		}
//		else
//		{
//			show[x-1][y] = count + '0';
//			win_up = 1;
//		}
//		//下
//		if ((count = get_mine_count(mine, x + 1, y)) == 0)
//		{
//			show[x+1][y] = '0';
//			win_down = Show_Together(show, mine, x + 1, y) + 1;
//		}
//		else
//		{
//			show[x+1][y] = count + '0';
//			win_down = 1;
//		}
//		//左
//		if ((count = get_mine_count(mine, x, y-1)) == 0)
//		{
//			show[x][y-1] = '0';
//			win_left = Show_Together(show, mine, x , y-1) + 1;
//		}
//		else
//		{
//			show[x][y-1] = count + '0';
//			win_left = 1;
//		}
//		//右
//		if ((count = get_mine_count(mine, x, y+1)) == 0)
//		{
//			show[x][y+1] = '0';
//			win_right = Show_Together(show, mine, x , y+1) + 1;
//		}
//		else
//		{
//			show[x][y+1] = count + '0';
//			win_right = 1;
//		}
//		//右上
//		if ((count = get_mine_count(mine, x-1, y+1)) == 0)
//		{
//			show[x-1][y+1] = '0';
//			win_rightup = Show_Together(show, mine, x-1 , y+1) + 1;
//		}
//		else
//		{
//			show[x-1][y+1] = count + '0';
//			win_rightup = 1;
//		}
//		//右下
//		if ((count = get_mine_count(mine, x+1, y+1)) == 0)
//		{
//			show[x+1][y+1] = '0';
//			win_rightdown = Show_Together(show, mine, x+1 , y+1) + 1;
//		}
//		else
//		{
//			show[x+1][y+1] = count + '0';
//			win_rightdown = 1;
//		}
//		//左下
//		if ((count = get_mine_count(mine, x+1, y-1)) == 0)
//		{
//			show[x+1][y-1] = '0';
//			win_leftdown = Show_Together(show, mine, x+1 , y-1) + 1;
//		}
//		else
//		{
//			show[x+1][y-1] = count + '0';
//			win_leftdown = 1;
//		}
//		//左上
//		if ((count = get_mine_count(mine, x-1, y-1)) == 0)
//		{
//			show[x-1][y-1] = '0';
//			win_leftup = Show_Together(show, mine, x-1 , y-1) + 1;
//		}
//		else
//		{
//			show[x-1][y-1] = count + '0';
//			win_leftup = 1;
//		}
//		return (win_up + win_down + win_left + win_right + win_leftup + win_leftdown + win_rightup + win_rightdown);
//	}
//	else
//		return 0;
//}

//排雷
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
				//该点位周围有几个雷
				int count = get_mine_count(mine, x, y);
				//周围有雷则只开一格
				//if(!count == 0)
				//{
					//在该点显示雷的数量
					show[x][y] = count + '0';
					//显示排查面板
					DisplayBoard(show, ROW, COL);
					win++;
				//}
				//否则连开
				//else
				//{
				//将所排查的这一格周围所有无雷格的3x3区域显示出来,并返回连续排查的数量
				//win += Show_Together(show, mine, x, y);
				//DisplayBoard(show, ROW, COL);
				//}
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
