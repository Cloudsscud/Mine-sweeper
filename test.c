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
	//�׵Ĵ����Ϣ

	//���úõ��׵���Ϣ
	char mine[ROWS][COLS];

	//�Ų��е��׵���Ϣ
	char show[ROWS][COLS];

	//��ʼ��
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//��ӡ����
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//������
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);

	//ɨ��
	FindMine(mine, show, ROW, COL);
}

void test()
{
	int input;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("������:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n\n");
			break;
		default :
			printf("ѡ���������ѡ\n\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
