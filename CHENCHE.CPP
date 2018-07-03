#include"chenche.h"

void chenche()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"D:\\borlandC\\bgi");
	
	drawgetup();
	
    int m=600;
	int n=290;
	int k=0;
	int t=0;
	while(1)//判断方向键
	{
		k=bioskey(0);
		if((k==0x4b00)&&(m>0))
		{
			setfillstyle(1,LIGHTGRAY);
			bar(m-75,n-21,m+75,n+200);
			body1(m-5,n);
			t=0;
			m=m-5;
			k=0;
		}
		else  if((k==0x4d00)&&(m<600))
		{
			setfillstyle(1,LIGHTGRAY);
			bar(m-75,n-21,m+75,n+200);
			body2(m+5,n);
			t=1;
			m=m+5;
			k=0;
		}
		else if((k==0x4800)&&(n>220))
		{
			if(t==0)
			{
				setfillstyle(1,LIGHTGRAY);
				bar(m-75,n-21,m+75,n+200);
				body1(m,n-5);
				n=n-5;
				k=0;
			}
			if(t==1)
			{
				setfillstyle(1,LIGHTGRAY);
				bar(m-75,n-21,m+75,n+200);
				body2(m,n-5);
				n=n-5;
				k=0;
			}
		}
		else if((k==0x5000)&&(n<400))
		{
			if(t==0)
			{
				setfillstyle(1,LIGHTGRAY);
				bar(m-75,n-21,m+75,n+200);
				body1(m,n+5);
				n=n+5;
				k=0;
			}
			if(t==1)
			{
				setfillstyle(1,LIGHTGRAY);
				bar(m-75,n-21,m+75,n+200);
				body2(m,n+5);
				n=n+5;
				k=0;
			}
		}
		else
		{
			k=0;
		}
		if((m==315)&&(n==220))//判定上车是否成功
		{
			settextstyle(3,0,4);
			setcolor(RED);
			outtextxy(200,420,"SUCCESSFUL!");
			getch();
			delay(1000);
			closegraph();
			break;
		}
	}
}

void drawgetup()//画出基本界面
{
	setlinestyle(0,0,3);
	moveto(0,198);
	lineto(640,198);
	setfillstyle(1,LIGHTGRAY);
	floodfill(10,210,WHITE);
	arc(60,60,90,180,60);
	moveto(500,0);
	lineto(640,100);
	setfillstyle(1,YELLOW);
	floodfill(60,60,WHITE);

	setfillstyle(1,LIGHTBLUE);
	int a[6]={50,130,210,370,450,520};
	int i;
	for(i=0;i<6;i++)
	{
		bar(a[i],80,30+a[i],110);
	}

	bar(280,80,340,200);
	body1(600,290);
}