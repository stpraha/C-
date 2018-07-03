#include"shubiao.h"

#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<bios.h>
#include<dos.h>
#include<conio.h>

union REGS regs;

/****画鼠标，此处由于为了实现鼠标的实心化，所以全部用线完成****/   
void cursor(int x, int y)
{
	setwritemode(XOR_PUT);
	setlinestyle(0,0,1);
	setcolor(BLACK);	
  line(x,y,x+11,y+11);
  line(x+10,y+11,x+8,y+11);
  line(x+7,y+11,x+10,y+19);
  line(x+9,y+20,x+8,y+20);
  line(x+7,y+19,x+4,y+12);
  line(x+3,y+13,x+1,y+15);
  line(x,y+16,x,y+1);
  setcolor(WHITE);  
  line(x+1,y+2,x+1,y+14);
  line(x+2,y+3,x+2,y+13);
  line(x+3,y+4,x+3,y+12);
  line(x+4,y+5,x+4,y+11);
  line(x+5,y+6,x+5,y+13);
  line(x+6,y+7,x+6,y+15);
  line(x+7,y+8,x+7,y+10);
  line(x+7,y+14,x+7,y+17);
  line(x+8,y+9,x+8,y+10);
  line(x+8,y+16,x+8,y+19);
  line(x+9,y+10,x+9,y+10);
  line(x+9,y+18,x+9,y+19);	
	setwritemode(COPY_PUT);
}


/*****初始化鼠标*****/
/*调用7、8号功能确定鼠标位置的极限位置*/
int initmouse(int xmi, int xma, int ymi, int yma)
{
	int retcode;
	regs.x.ax=0;
	int86(51,&regs,&regs);
	retcode=regs.x.ax;
	if(0==retcode)
	{
		return 0;
	}
	regs.x.ax = 7;
	regs.x.cx = xmi;
	regs.x.dx = xma;
	int86(51, &regs, &regs);
	regs.x.ax = 8;
	regs.x.cx = ymi;
	regs.x.dx = yma;
	int86(51, &regs, &regs);
	return retcode;
}

/***调用系统中断得到热键位置和鼠标状态***/
int readmouse(int *mx, int *my,int *mbutt)
{
	int xx0 = *mx;
	int yy0 = *my;
	int but0 = 0;
	int mb;
	int xnew;
	int ynew;
	do
	{
		regs.x.ax = 3;
		int86(51, &regs, &regs);
		xnew = regs.x.cx;
		ynew = regs.x.dx;
		*mbutt = regs.x.bx;
	}while (xnew==xx0&&ynew==yy0&&*mbutt==but0);
		*mx = xnew;
		*my = ynew;
		if(*mbutt)
		{
		 return 1;
		}
		else
		{
		 return 0;
		}
}
//获取鼠标点饥
int readclick(int *mbutt)
{
	int but0 = 0;
	int mb;
	do
	{
		regs.x.ax = 3;
		int86(51, &regs, &regs);
		*mbutt = regs.x.bx;
	}while (*mbutt==but0);
		if(*mbutt)
		{
		 return 1;
		}
		else
		{
		 return 0;
		}
}

void newmouse(int *mx, int*my, int*mbutt)
{
		int xx0 = *mx;
		int yy0 = *my;

		int xm;
		int ym;
		readmouse(&xm, &ym,mbutt);
		if(xm!=*mx||ym!=*my)
		{
			cursor(xx0, yy0);
			cursor(xm, ym);
			*mx = xm;
			*my = ym;
                 /*
		 if(mbutt)
		 {
		  cursor(xx0,yy0);
                  cursor(xm,ym);
		 }
                 */
		}
 }

void hnewmouse(int *mx, int*my, int*mbutt)     

{
		 
		int xm;                                                                                       
		int ym;                                                                                       
		readmouse(&xm, &ym, mbutt);                                                         
		*mx = xm;                                                                                     
		*my = ym;                                                                                     
} 

