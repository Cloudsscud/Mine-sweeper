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
				//�жϸõ�λ��Χ�м�����
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
				win++;
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
