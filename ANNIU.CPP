#include"anniu.h"


void button(int x1,int y1,int x2,int y2)//按钮未按下状态
{
	int WIDTH=5;
	int i;
	setfillstyle(1,LIGHTGRAY);
	bar(x1,y1,x2,y2);
	for(i=0;i<WIDTH;i++)
	{
		setcolor(WHITE);
		moveto(x1-WIDTH+i,y1-WIDTH+i);
		lineto(x2,y1-WIDTH+i);
		setcolor(YELLOW);
		moveto(x1-WIDTH+i,y1-WIDTH+i);
		lineto(x1-WIDTH+i,y2);
	}
	setcolor(RED);
	rectangle(x1-WIDTH,y1-WIDTH,x2,y2);
}

void buttondown(int x1,int y1,int x2,int y2)//按钮按下状态
{
	int WIDTH=5;
	int i;
	setfillstyle(1,WHITE);
	bar(x1,y1,x2,y2);
	for(i=0;i<WIDTH;i++)
	{
		setcolor(YELLOW);
		moveto(x1-WIDTH+i,y1-WIDTH+i);
		lineto(x2,y1-WIDTH+i);
		setcolor(LIGHTGRAY);
		moveto(x1-WIDTH+i,y1-WIDTH+i);
		lineto(x1-WIDTH+i,y2);
	}
}

void station(int x,int y)//普通站点
{
	setcolor(YELLOW);
	circle(x,y,2);
	circle(x,y,3);
	setcolor(LIGHTBLUE);
	circle(x,y,4);
	circle(x,y,5);
}

void stationb(int x,int y)//大站点
{
	setcolor(GREEN);
	circle(x,y,4);
	circle(x,y,3);
	setcolor(LIGHTGRAY);
	circle(x,y,5);
	circle(x,y,6);
}

void stationdown(int x,int y)//站点被选中状态
{
	setcolor(RED);
	circle(x,y,2);
	circle(x,y,3);
	setcolor(WHITE);
	circle(x,y,4);
	circle(x,y,5);
}

void stationdownb(int x,int y)//大站被选状态
{
	setcolor(RED);
	circle(x,y,3);
	circle(x,y,4);
	circle(x,y,5);
	setcolor(GREEN);
	circle(x,y,6);
	circle(x,y,7);
	setcolor(WHITE);
	circle(x,y,8);
}