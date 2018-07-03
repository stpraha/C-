#include"chuzhan.h"

void chuzhan()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"D:\\borlandC\\bgi");

	int i,m=0;

	cleardevice();
	setbkcolor(YELLOW);
	setfillstyle(1,LIGHTGRAY);
	bar(0,450,639,500);
	
	showtime();
	setcolor(RED);
	settextstyle(3,0,1);
	
	//列车出站动画
	for(i=400;i>=0;i=i-10)
	{
		m++;
		setcolor(BLUE);
		setfillstyle(1,YELLOW);
		bar(0,280,639,450);
		setfillstyle(0,WHITE);
		setlinestyle(0,0,2);
		moveto(0,280);
		lineto(i+52,280);
		moveto(i+70,290);
		lineto(0,290);
		arc(i+52,300,30,100,20);
		moveto(i+70,290);
		lineto(i+210,410);
		lineto(0,410);
		arc(i+175,430,0,30,40);
		arc(i+175,430,330,360,40);
		moveto(i+210,450);
		lineto(0,450);

		setfillstyle(1,WHITE);
		floodfill(30,390,BLUE);
		setfillstyle(1,LIGHTBLUE);
		floodfill(30,445,BLUE);
		floodfill(30,285,BLUE);

		setfillstyle(1,LIGHTBLUE);
		if(i>350)
		{
			bar(i-350,330,i-300,380);
		}
		if(i>250)
		{
			bar(i-250,330,i-200,380);
		}  
		if(i>150)
		{
			bar(i-150,330,i-100,380);
		}
		if(i>50)
		{
			bar(i-50,330,i,380);
		}
		bar(i+50,330,i+100,380);
		
		settextstyle(3,0,1);
		outtextxy(i+90,415,"HE XIE HAO");
		setfillstyle(1,YELLOW);
		
		if(m%24==0)
		{
			puts12(580,200,"全",RED,3,3);
		}
		if(m%21==0)
		{
			puts12(500,200,"安",RED,3,3);
		}
		if(m%18==0)
		{
			puts12(420,200,"意",RED,3,3);
		}
		if(m%15==0)
		{
			puts12(340,200,"注",RED,3,3);
		}
		if(m%12==0)
		{
			puts12(260,200,"站",RED,3,3);
		}
		if(m%9==0)
		{
			puts12(180,200,"出",RED,3,3);
		}
		if(m%6==0)
		{
			puts12(100,200,"车",RED,3,3);
		}
		if(m%3==0)
		{
			puts12(20,200,"列",RED,3,3);
		}

		delay(760-((400-i)/20)*25);
	}
	setcolor(YELLOW);
	bar(0,180,640,260);
	bar(0,280,640,450);
	puts12(50,100,"列车已离站，谢谢乘坐，祝您愉快！",RED,3,3);
	delay(2000);
	closegraph();
}