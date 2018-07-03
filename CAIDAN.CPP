#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<bios.h>
#include<alloc.h>
#include<dos.h>
#include<ctype.h>
#include<CONIO.H>
#include<string.h>
#include<io.h>
#include<stdio.h>
#include<dos.h>
#include"hanzi1.h"
#include"donhua.h"
#include"jinzhi.h"
#include"shubiao.h"
#include"toubi.h"
#include"caidan.h"
#include"shubiao.h"


int caidan()
{


	int driver=VGA;
	int mode=VGAHI;
	initgraph(&driver,&mode,"D:\\BORLANDC\\bgi");
	int flagg;
	caidantu();
	flagg=caidanxuanze();
	closegraph();
	return flagg;



}



void caidantu()
{

    int d1[]={1,1,637,1,637,477,1,477,1,1};
	cleardevice();
	setviewport(1,1,639,479,1);
	clearviewport ();
	setbkcolor(11);
	setcolor(RED);
	setfillstyle(11,6);
	fillpoly(4,d1);
	setviewport(10,10,630,470,1);
	clearviewport();
	setfillstyle(1,WHITE);
	bar(200,10,400,50);
	hanzi("地铁购票系统",205,15,30,2,2,RED);
	setfillstyle(1,WHITE);
	bar(80,60,540,400);
	setcolor(RED);
	setfillstyle(1,11);
	ellipse(310,230,0,360,45,30);
	floodfill(310,230,RED);
	hanzi("开始购票",270,220,20,1,1,RED);
	setfillstyle(1,11);
	ellipse(310,110,0,360,45,30);
	floodfill(310,110,RED);
	hanzi("说明",280,100,20,1,1,RED);
	/*setfillstyle(1,11);
	ellipse(160,230,0,360,45,30);
	floodfill(160,230,RED);
	hanzi("地铁通",140,220,20,1,1,RED) ;
	setfillstyle(1,11);
	ellipse(310,350,0,360,45,30);
	floodfill(310,350,RED);
	hanzi("地铁动画",275,340,20,1,1,RED);*/
	setfillstyle(1,11);
	ellipse(460,230,0,360,45,30);
	floodfill(460,230,RED);
	hanzi("开始投币",427,220,20,1,1,RED);
	setcolor(BLACK);
	line(310,140,310,200);
	//line(265,230,205,230);
	//line(310,260,310,320);
	line(355,230,415,230);

	/*huatuichukuang*/
	setcolor(RED);
	setfillstyle(1,7);
	line(500,410,580,410);
	line(500,450,580,450);
	arc(500,430,90,270,20);
	arc(580,430,0,90,20);
	arc(580,430,270,360,20);
	floodfill(550,430,RED);
	hanzi("退出程序",510,420,20,1,1,RED);
}

/*鼠标特效及点击选择*/
int caidanxuanze()
{
	int ky;
	int mouse_x=0,mouse_y=0,mouseclick=0;
	initmouse(1,630,1,470);
	cursor(mouse_x,mouse_y);
	while(1)
	{
		/*shubiao texiao*/
		newmouse(&mouse_x,&mouse_y,&mouseclick);
		
		//kaishigoupiao
		if(270<mouse_x&&mouse_x<350&&mouse_y>200&&mouse_y<260)
		{
			setcolor(YELLOW);
			setfillstyle(1,7);
			ellipse(310,230,0,360,45,30);
			floodfill(310,230,YELLOW);
			hanzi("开始购票",270,220,20,1,1,RED);
			delay(100);
		}
		
			//kaishixuanzan
		else if(mouse_x>270&&mouse_x<350&&mouse_y>80&&mouse_y<140)
		{
			
			setcolor(YELLOW);
			setfillstyle(1,7);
			ellipse(310,110,0,360,45,30);
			floodfill(310,125,YELLOW);
			hanzi("说明",280,100,20,1,1,RED);
			delay(100);

		}


		//ditieton
		/*else if(mouse_x>120&&mouse_x<200&&mouse_y>200&&mouse_y<260)
		{

			setcolor(YELLOW);
			setfillstyle(1,7);
			ellipse(160,230,0,360,45,30);
			floodfill(160,230,YELLOW);
			hanzi("地铁通",140,220,20,1,1,RED) ;
			delay(100);
		}

		//ditie donhua
		else if(mouse_x>270&&mouse_x<350&&mouse_y>320&&mouse_y<380)
		{
			setfillstyle(1,WHITE);
			bar(265,320,355,380);
			setcolor(RED);
			setfillstyle(1,7);
			ellipse(310,350,0,360,45,30);
			floodfill(310,350,RED);
			hanzi("地铁动画",275,340,20,1,1,RED);
			delay(100);

		}*/

		//kaishi toubi
		else if(mouse_x>420&&mouse_x<500&&mouse_y>200&&mouse_y<260)
		{

			setcolor(YELLOW);
			setfillstyle(1,7);
			ellipse(460,230,0,360,45,30);
			floodfill(460,245,YELLOW);
			hanzi("开始投币",427,220,20,1,1,RED);
			delay(100);

		}
		else
		{
			setcolor(RED);
			setfillstyle(1,11);
			ellipse(310,230,0,360,45,30);
			floodfill(310,230,RED);
			hanzi("开始购票",270,220,20,1,1,RED);

			setcolor(RED);
			setfillstyle(1,11);
			ellipse(310,110,0,360,45,30);
			floodfill(310,125,RED);
			hanzi("说明",280,100,20,1,1,RED);

			/*setcolor(RED);
			setfillstyle(1,11);
			ellipse(160,230,0,360,45,30);
			floodfill(160,230,RED);
			hanzi("地铁通",140,220,20,1,1,RED) ;
			setcolor(RED);
			setfillstyle(1,11);
			ellipse(310,350,0,360,45,30);
			floodfill(310,350,RED);
			hanzi("地铁动画",275,340,20,1,1,RED);*/


			setcolor(RED);
			setfillstyle(1,11);
			ellipse(460,230,0,360,45,30);
			floodfill(460,245,RED);
			hanzi("开始投币",427,220,20,1,1,RED);

		}
			/*确认开始购票*/
			/*xuanze kaishigoupiao*/
		if(270<mouse_x&&mouse_x<350&&mouse_y>200&&mouse_y<260&&mouseclick!=0)
		{
			setcolor(YELLOW);
			setfillstyle(1,4);
			ellipse(310,230,0,360,45,30);
			floodfill(310,230,YELLOW);
			hanzi("开始购票",270,220,20,1,1,RED);

						return 1;
			break;

		}
		//shuoming
		if(mouse_x>270&&mouse_x<350&&mouse_y>80&&mouse_y<140&&mouseclick!=0)
		{

			setcolor(YELLOW);
			setfillstyle(1,7);
			ellipse(310,110,0,360,45,30);
			floodfill(310,110,YELLOW);
			hanzi("开始选站",280,100,20,1,1,RED);
			return 2;
		}
		/*if(mouse_x>270&&mouse_x<350&&mouse_y>320&&mouse_y<380&&mouseclick!=0)
		{
			setfillstyle(1,WHITE);
			bar(265,320,355,380);
			setcolor(RED);
			setfillstyle(1,7);
			ellipse(310,350,0,360,45,30);
			floodfill(310,350,RED);
			hanzi("地铁动画",275,340,20,1,1,RED);
			delay(100);
			return 1;

		}*/
		//queren kaishi toubi
		if(mouse_x>420&&mouse_x<500&&mouse_y>200&&mouse_y<260&&mouseclick!=0)
		{

			setcolor(YELLOW);
			setfillstyle(1,7);
			ellipse(460,230,0,360,45,30);
			floodfill(460,230,YELLOW);
			hanzi("开始投币",427,220,20,1,1,RED);
			//toubijiemian();
			return 10;

		
		}
		
		
		/*texiao*/

		if(mouse_x>480&&mouse_x<600&&mouse_y>410&&mouse_y<450)
		{

			setcolor(YELLOW);
			setfillstyle(1,11);
			line(500,410,580,410);
			line(500,450,580,450);
			arc(500,430,90,270,20);
			arc(580,430,0,90,20);
			arc(580,430,270,360,20);
			floodfill(550,430,YELLOW);
			hanzi("退出程序",510,420,20,1,1,RED);
			delay(100)  ;

		}
		else
		{
			setcolor(RED);
			setfillstyle(1,7);
			line(500,410,580,410);
			line(500,450,580,450);
			arc(500,430,90,270,20);
			arc(580,430,0,90,20);
			arc(580,430,270,360,20);
			floodfill(550,430,RED);
			hanzi("退出程序",510,420,20,1,1,RED);
		}
		if(mouse_x>480&&mouse_x<600&&mouse_y>410&&mouse_y<450&&mouseclick!=0)
		{
			setcolor(YELLOW);
			setfillstyle(1,11);
			line(500,410,580,410);
			line(500,450,580,450);
			arc(500,430,90,270,20);
			arc(580,430,0,90,20);
			arc(580,430,270,360,20);
			floodfill(550,430,YELLOW);
			hanzi("退出程序",510,420,20,1,1,RED);

				exit(0);
		}
	
	}

}




