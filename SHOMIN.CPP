#include"jinzhan.h"

void shuomin()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"D:\\borlandC\\bgi");

	setfillstyle(1,WHITE);
	bar(0,0,640,460);
	puts12(3,40,"地铁模拟运行及自动售票系统",BLACK,4,4);
	puts12(145,203,"祝您路途愉快一路顺风",RED,3,3);
	puts12(102,313,"作者",RED,2,2);
	puts12(170,313,"陈旭东",BLUE,2,2);
	settextstyle(0,0,2);
	setcolor(BLACK);
	outtextxy(265,316,"U201314538");
        outtextxy(265,346,"U201314552");
	puts12(170,343,"肖标",BLUE,2,2);
	puts12(430,313,"自动化学院",RED,2,2);
	puts12(430,343,"一三零一班",BLUE,2,2);
	puts12(500,440,"自动化学院版权所有",BLACK,1,1);
	
	getch();
	cleardevice();

	bar(0,0,640,460);
	puts12(102,43,"请在主菜单选择选站或是投币出票",RED,2,2);
	puts12(102,93,"在进入选站后可以更改出发站",RED,2,2);
	puts12(102,143,"在进入选站后可以更改终点站和需要的票数",RED,2,2);
	puts12(102,193,"然后点确定也可以进入投币界面",RED,2,2);
	puts12(102,243,"或者点退出返回主菜单",RED,2,2);
	puts12(102,293,"投币界面也可以返回主菜单",RED,2,2);
	puts12(102,343,"其实很好懂",RED,2,2);
	puts12(102,393,"记得给好评谢谢",BLUE,2,2);
	circle(460,300,10);
	circle(500,300,10);
	circle(480,320,60);
	setfillstyle(1,BLACK);
	floodfill(460,300,BLACK);
	floodfill(500,300,BLACK);
	moveto(480,320);
	lineto(475,340);
	lineto(485,340);
	moveto(450,350);
	lineto(470,360);
	lineto(490,360);
	lineto(510,350);
	lineto(450,350);
	setfillstyle(1,RED);
	floodfill(470,353,BLACK);
	
	getch();
	closegraph();
}