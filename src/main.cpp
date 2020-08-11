#include "snake.h"
#include <graphics.h>
#define Azure LIGHTBLUE		//背景色
#define LineColor MAGENTA	//线条色
#define FillColor 0xFF55FF	//填充色

int main()
{
	PlaySound(L"..\\..\\..\\asset\\sea.wav", NULL, SND_ASYNC | SND_LOOP);
	srand((unsigned int)time(NULL));
	insnake();	//初始化

	while (1)
	{
		cleardevice();	//清屏函数
		if (food.flag == 0)	//若无食物，产生食物
		{
			foodxy();
		}
		inifood();	//绘制食物
		inisnake();	//绘制蛇身
		snakedie();	//判断死亡与否
		eatfood();	//判断是否吃到食物
		way();	//蛇的身体坐标
		Sleep(100);
		while (_kbhit())//检测按键
		{
			again();
			snakemove();//蛇前进方向
			way();
		}
	}

	while (1);
	closegraph();
	return 0;
}

//初始化
void insnake()
{
	initgraph(640, 480);
	IMAGE img;	// 定义 IMAGE 对象
	loadimage(&img, _T("..\\..\\..\\asset\\bg.png"));	// 读取图片到 img 对象中
	putimage(0, 0, 640, 480, &img, 0, 0);	// 在坐标 (0, 0) 位置显示 IMAGE 对象

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
//绘制蛇
void inisnake()
{
	for (int i = 0; i < snake.num; i++)
	{
		setlinecolor(LineColor);
		setfillcolor(FillColor);
		fillrectangle(snake.xy[i].x, snake.xy[i].y, snake.xy[i].x + 10, snake.xy[i].y + 10);
	}
}
//蛇的移动
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
//蛇的方向控制
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
//食物坐标获取
void foodxy()
{
	food.fdxy.x = rand() % 63 * 10;
	food.fdxy.y = rand() % 47 * 10;
	food.flag = 1;

	for (int i = 0; i < snake.num; i++)	//防止食物与蛇身重合
	{
		if (food.fdxy.x == snake.xy[i].x && food.fdxy.y == snake.xy[i].y)
		{
			foodxy();
		}
	}
}
//绘制食物
void inifood()
{
	fillrectangle(food.fdxy.x, food.fdxy.y, food.fdxy.x + 10, food.fdxy.y + 10);
}
//食物判断
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
//判断蛇是否死亡
void snakedie()
{
	/*TCHAR grade[100] = { 0 };
	printf(char*)grade, "%d", food.eatgrade);
	setbkmode(0);
	settextcolor(WHITE);
	settextstyle(22, 8, TEXT("微软雅黑 Light"), 0, 0, 500, false, false, false);
	outtextxy(550, 20, TEXT("分数: "));
	settextstyle(20, 8, TEXT("微软雅黑 Light"));
	outtextxy(600, 21, TCHAR(grade));*/

	if (snake.xy[0].x > 630 || snake.xy[0].x < 0 || snake.xy[0].y>470 || snake.xy[0].y < 0)
	{
		outtextxy(240, 320, TEXT("撞墙了，游戏结束"));
		MessageBox(0, TEXT("撞墙了，游戏结束"), TEXT("弟弟操作"), 0);
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
		outtextxy(240, 320, TEXT("暂停"));
		while (_getch() != 32);
	}
}