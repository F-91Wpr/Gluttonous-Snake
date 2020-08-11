#pragma once

#define _CRT_SECURE_NO_WARNINGS
#ifndef __SNAKE_H_
#define __SNAKE_H_
#define MAX 500
#pragma message("贪吃龙")
#include <stdio.h>
#include<windows.h>
#include<conio.h>	//控制台输入输出
#include<time.h>
#include "Mmsystem.h"//导入声音头文件
#pragma comment(lib,"winmm.lib")//导入声音头文件库

//初始化蛇
void insnake();
//绘制蛇
void inisnake();
//蛇的移动
void way();
//
void clsnake();
//蛇的方向
void snakemove();
//蛇的食物
void foodxy();
//食物绘制
void inifood();
//判断蛇是否吃掉食物
void eatfood();
////判断蛇是否挂掉
void snakedie();
//游戏过程中空格键暂停，开始
void again();


//存储蛇的坐标的结构体
typedef struct coor {
	int x;
	int y;
}coor;

//蛇的基本属性
struct snake {
	int num;	//长度
	coor xy[MAX];	//蛇身数组
	char way;
}snake;

//食物的基本属性
struct food {
	coor fdxy;
	int flag;
	int eatgrade;
}food;

enum way {
	up = 72,
	down = 80,
	left = 75,
	right = 77
};
#endif
