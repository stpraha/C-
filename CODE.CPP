#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<string.h>
int code()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"d:\\borlandC\\bgi");
	char *i="199409";
	char *j;
	setcolor(LIGHTBLUE);
	bar(0,0,640,480);
	setcolor(BLACK);
	rectangle(120,190,300,240);
	settextstyle(0,0,3);
	outtextxy(0,200,"code:");
	gets(j);
	settextstyle(0,0,2);
	outtextxy(120,210,j);
	if(strcmp(i,j)==0)
	{
	settextstyle(0,0,4);
	outtextxy(400,300,"OK");
	getch();
	closegraph();
	return 1;

	}
	else
	{
	settextstyle(0,0,4);
	 outtextxy(400,300,"WRONG");
	 getch();
	 closegraph();
	 return 0;
	}
}