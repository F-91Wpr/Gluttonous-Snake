#include "snake.h"
#include <graphics.h>
#define Azure LIGHTBLUE		//����ɫ
#define LineColor MAGENTA	//����ɫ
#define FillColor 0xFF55FF	//���ɫ

int main()
{
	PlaySound(L"..\\..\\..\\asset\\sea.wav", NULL, SND_ASYNC | SND_LOOP);
	srand((unsigned int)time(NULL));
	insnake();	//��ʼ��

	while (1)
	{
		cleardevice();	//��������
		if (food.flag == 0)	//����ʳ�����ʳ��
		{
			foodxy();
		}
		inifood();	//����ʳ��
		inisnake();	//��������
		snakedie();	//�ж��������
		eatfood();	//�ж��Ƿ�Ե�ʳ��
		way();	//�ߵ���������
		Sleep(100);
		while (_kbhit())//��ⰴ��
		{
			again();
			snakemove();//��ǰ������
			way();
		}
	}

	while (1);
	closegraph();
	return 0;
}

//��ʼ��
void insnake()
{
	initgraph(640, 480);
	IMAGE img;	// ���� IMAGE ����
	loadimage(&img, _T("..\\..\\..\\asset\\bg.png"));	// ��ȡͼƬ�� img ������
	putimage(0, 0, 640, 480, &img, 0, 0);	// ������ (0, 0) λ����ʾ IMAGE ����

	settextcolor(FillColor);
	settextstyle(20, 13, TEXT("Consolas"), 0, 0, 300, false, true, false);
	outtextxy(250, 330, TEXT(". any key"));
	_getch();
	setbkcolor(Azure);
	snake.xy[2].x = 0;
	snake.xy[2].y = 0;
	snake.xy[1].x = 10;
	snake.xy[1].y = 0;
	snake.xy[0].x = 20;
	snake.xy[0].y = 0;
	snake.num = 3;
	snake.way = right;
	food.flag = 0;
}
//������
void inisnake()
{
	for (int i = 0; i < snake.num; i++)
	{
		setlinecolor(LineColor);
		setfillcolor(FillColor);
		fillrectangle(snake.xy[i].x, snake.xy[i].y, snake.xy[i].x + 10, snake.xy[i].y + 10);
	}
}
//�ߵ��ƶ�
void way()
{
	for (int i = snake.num - 1; i > 0; i--)
	{
		snake.xy[i].x = snake.xy[i - 1].x;
		snake.xy[i].y = snake.xy[i - 1].y;
	}
	switch (snake.way)
	{
	case right:
		snake.xy[0].x += 10;
		break;
	case left:
		snake.xy[0].x -= 10;
		break;
	case down:
		snake.xy[0].y += 10;
		break;
	case up:
		snake.xy[0].y -= 10;
		break;
	default:
		break;
	}
}
//�ߵķ������
void snakemove()
{
	char ch = 0;
	ch = _getch();
	switch (ch)
	{
	case up:
		if (snake.way != down)
			snake.way = up;
		break;
	case left:
		if (snake.way != right)
			snake.way = left;
		break;
	case right:
		if (snake.way != left)
			snake.way = right;
		break;
	case down:
		if (snake.way != up)
			snake.way = down;
		break;
	default:
		break;
	}
}
//ʳ�������ȡ
void foodxy()
{
	food.fdxy.x = rand() % 63 * 10;
	food.fdxy.y = rand() % 47 * 10;
	food.flag = 1;

	for (int i = 0; i < snake.num; i++)	//��ֹʳ���������غ�
	{
		if (food.fdxy.x == snake.xy[i].x && food.fdxy.y == snake.xy[i].y)
		{
			foodxy();
		}
	}
}
//����ʳ��
void inifood()
{
	fillrectangle(food.fdxy.x, food.fdxy.y, food.fdxy.x + 10, food.fdxy.y + 10);
}
//ʳ���ж�
void eatfood()
{
	if (snake.xy[0].x == food.fdxy.x && snake.xy[0].y == food.fdxy.y)
	{
		//		PlaySound("BUL.wav",NULL, SND_FILENAME|SND_ASYNC);
		snake.num++;
		food.eatgrade += 10;
		food.flag = 0;
	}
}
//�ж����Ƿ�����
void snakedie()
{
	/*TCHAR grade[100] = { 0 };
	printf(char*)grade, "%d", food.eatgrade);
	setbkmode(0);
	settextcolor(WHITE);
	settextstyle(22, 8, TEXT("΢���ź� Light"), 0, 0, 500, false, false, false);
	outtextxy(550, 20, TEXT("����: "));
	settextstyle(20, 8, TEXT("΢���ź� Light"));
	outtextxy(600, 21, TCHAR(grade));*/

	if (snake.xy[0].x > 630 || snake.xy[0].x < 0 || snake.xy[0].y>470 || snake.xy[0].y < 0)
	{
		outtextxy(240, 320, TEXT("ײǽ�ˣ���Ϸ����"));
		MessageBox(0, TEXT("ײǽ�ˣ���Ϸ����"), TEXT("�ܵܲ���"), 0);
		getchar();
	}
	for (int i = 1; i < snake.num; i++)
	{
		if (snake.xy[0].x == snake.xy[i].x && snake.xy[0].y == snake.xy[i].y)
		{
			outtextxy(240, 320, TEXT("DIE"));
			getchar();
		}
	}
}

void again()
{
	if (_getch() == 32)
	{
		outtextxy(240, 320, TEXT("��ͣ"));
		while (_getch() != 32);
	}
}