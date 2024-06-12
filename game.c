#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

//��ʼ�����
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

//��ʾ���
void DisplayBoard(char board[ROWS][COLS], int row, int col)	//��������
{
	int i = 0;
	int j = 0;
	printf("----------ɨ��-----------\n");
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);//��ӡ������
	}

	for (i = 1; i <= row; i++)
	{
		printf("\n");
		printf("%d ", i);//��ӡ������
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);//���ε��ַ���ӡ
		}
	}
	printf("\n----------ɨ��-----------\n");
}

//void DisplayBoard(char board[ROW][COL], int row, int col)	//�ÿ�����bug
//{
//	int i;
//	int j;
//	//��ӡ�к�
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

//������ͼ
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;//������
	while (count)//ֱ��������Ϊ0
	{
		int x = rand() % row + 1;//1-9
		int y = rand() % col + 1;//
		if (board[x][y] == '0')
		{
			board[x][y] = '1';//��Ϊ�հ�0����������1
			count--;//ʣ����������һ
		}
	}
}

//�ҳ����Ų�������3x3�����ж�����
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

////�����Ų�Ϊ�յ���һ����Χ3x3������ʾ��������������չ��������
//int Show_Together(char show[ROWS][COLS], char mine[ROWS][COLS], int x, int y)
//{
//	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)//�жϵ�λ�Ƿ�Ϸ�
//	{
//		//�Ų�����
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
//		//��Χ�˸��������
//		int count;
//		//��
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
//		//��
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
//		//��
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
//		//��
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
//		//����
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
//		//����
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
//		//����
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
//		//����
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

//����
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < col * row - EASY_COUNT)
	{
		printf("�������Ų��׵�����:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�Ϸ�
			//�ж��ǲ�����
			if (mine[x][y] == '1')//����
			{
				printf("���ź�����ʧ����\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else//������
			{
				//�õ�λ��Χ�м�����
				int count = get_mine_count(mine, x, y);
				//��Χ������ֻ��һ��
				//if(!count == 0)
				//{
					//�ڸõ���ʾ�׵�����
					show[x][y] = count + '0';
					//��ʾ�Ų����
					DisplayBoard(show, ROW, COL);
					win++;
				//}
				//��������
				//else
				//{
				//�����Ų����һ����Χ�������׸��3x3������ʾ����,�����������Ų������
				//win += Show_Together(show, mine, x, y);
				//DisplayBoard(show, ROW, COL);
				//}
			}
		}
		else
		{
			printf("�����������������!\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ����ʤ����^.^\n");
		DisplayBoard(mine, ROW, COL);
	}
}
