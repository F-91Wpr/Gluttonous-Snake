#pragma once

#define _CRT_SECURE_NO_WARNINGS
#ifndef __SNAKE_H_
#define __SNAKE_H_
#define MAX 500
#pragma message("̰����")
#include <stdio.h>
#include<windows.h>
#include<conio.h>	//����̨�������
#include<time.h>
#include "Mmsystem.h"//��������ͷ�ļ�
#pragma comment(lib,"winmm.lib")//��������ͷ�ļ���

//��ʼ����
void insnake();
//������
void inisnake();
//�ߵ��ƶ�
void way();
//
void clsnake();
//�ߵķ���
void snakemove();
//�ߵ�ʳ��
void foodxy();
//ʳ�����
void inifood();
//�ж����Ƿ�Ե�ʳ��
void eatfood();
////�ж����Ƿ�ҵ�
void snakedie();
//��Ϸ�����пո����ͣ����ʼ
void again();


//�洢�ߵ�����Ľṹ��
typedef struct coor {
	int x;
	int y;
}coor;

//�ߵĻ�������
struct snake {
	int num;	//����
	coor xy[MAX];	//��������
	char way;
}snake;

//ʳ��Ļ�������
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
