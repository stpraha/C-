#include"jinzhan.h"
#include<bios.h>

int jinzhan()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"D:\\borlandC\\bgi");

	int i;
	int size1;
	void *buffer;

	cleardevice();
	setbkcolor(YELLOW);
	setfillstyle(1,LIGHTGRAY);
	bar(0,450,639,500);
	
	showtime();

	//站名动画
	setfillstyle(1,BLUE);
	bar(450,30,620,80);
	setfillstyle(1,MAGENTA);
	bar(455,35,615,75);                                           
	puts12(460,40,"寝室站到了",YELLOW,2,2);
 
	for(i=0;i<5;i++)
	{
		setfillstyle(1,RED);
		bar(450,30,620,80);
		setfillstyle(1,LIGHTBLUE);
		bar(455,35,615,75);
		puts12(460,40,"寝室站到了",RED,2,2);
 
		delay(400);
 
		setfillstyle(1,BLUE);
		bar(450,30,620,80);
		setfillstyle(1,MAGENTA);
		bar(455,35,615,75);                                           
		puts12(460,40,"寝室站到了",YELLOW,2,2);

		delay(400);
	}
	/*
		setfillstyle(0,WHITE);
		setlinestyle(0,0,2);
		moveto(0,280);
		lineto(452,280);
		moveto(470,290);
		lineto(0,290);
		arc(452,300,30,100,20);
		moveto(470,290);
		lineto(610,410);
		lineto(0,410);
		arc(575,430,0,30,40);
		arc(575,430,330,360,40);
		moveto(610,450);
		lineto(0,450);

		setfillstyle(1,WHITE);
		floodfill(30,390,BLUE);
		setfillstyle(1,LIGHTBLUE);
		floodfill(30,445,BLUE);
		floodfill(30,285,BLUE);

		putimage(i,280,buffer,COPY_PUT);
		setfillstyle(1,LIGHTBLUE);
		
		
			bar(50,330,100,380);
		
		
		
			bar(150,330,200,380);
		
		
		
			bar(250,330,300,380);
		
		
		
			bar(350,330,4,380);
		
		bar(450,330,500,380);
	size1=imagesize(0,280,640,450);
	buffer=malloc(size1);
	getimage(0,280,640,450,buffer);
	bar(0,280,639,450);*/
	//列车进站动画
	for(i=0;i<=400;i=i+10)
	{
		setcolor(BLUE);
		setfillstyle(0,YELLOW);
		/*
		if(kbhit()&&bioskey(0))
		{
			setfillstyle(0,YELLOW);
			bar(0,280,639,450);
			i=400;
			bioskey(0);
		}
		*/
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

		//putimage(i,280,buffer,COPY_PUT);
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
		//outtextxy(i+90,415,"HE XIE");
		puts12(i+90,415,"和谐号",YELLOW,2,2);

		//putimage(i,280,buffer,COPY_PUT);
		setfillstyle(1,YELLOW);
		delay(350+(i/20)*25);
	}

	setcolor(YELLOW);
	rectangle(120,320,200,449);
	setfillstyle(1,BLUE);
	floodfill(151,352,YELLOW);
	floodfill(199,448,YELLOW);

	setfillstyle(1,LIGHTGRAY);
	bar(120,350,121,449);
	//列车开门动画
	for(i=0;i<=80;i=i+2)
	{
		bar(120+i,320,121,449);
		delay(100);
	}

	puts12(50,150,"列车已进站，请先下后上，小心礼让",RED,3,3);
 
	delay(2000);
	closegraph();
	return 1;
}