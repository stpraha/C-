
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<bios.h>
#include<dos.h>
#include<conio.h>
#include"mouse.h"

union REGS regs;



/****画鼠标，此处由于为了实现鼠标的实心化，所以全部用线完成****/
void huashubiao(int x, int y)
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
int readmouse(int *mx, int *my,int *mbutt)           //调用这个函数的作用是改变后面调用函数时定义的mosex,mosey,mousekey值
{
	int xx0 = *mx;                                                                                
	int yy0 = *my;                                                                                
	int but0 = 0;                                                                                 
	int mb;                                                                                       
	int xnew;                                                                                     
	int ynew;                                                                                     
	do                                 //如果鼠标位置或按键状态没有改变，就不会改变定义的值，出就是在函数里定义的mosex,mosey,mousekey值
	{                                                                                             
		regs.x.ax = 3;                                                                            
		int86(51, &regs, &regs);                                                                  
		xnew = regs.x.cx;                                                                         
		ynew = regs.x.dx;                                                                         
		*mbutt = regs.x.bx;                                                                       
	}while (xnew==xx0&&ynew==yy0&&*mbutt==but0);                                                  
		*mx = xnew; /*更新后的热键位置*/                                                                              
		*my = ynew;                                                                               
		return 0;                                                      
}

/****newmouse的作用是在得到的新热键处画鼠标并将原来的鼠标异或掉*****/    //与鼠标的按键无关                                                                                              
void newmouse(int *mx, int*my, int*mbutt)      //在新的位置画鼠标，并且会调用readmouse函数改变mosex,mosey,mousekey值	                         
{                                                                                                 
		int xx0 = *mx;                                                                                
		int yy0 = *my;                                                                                
		 
		int xm;                                                                                       
		int ym;                                                                                       
		readmouse(&xm, &ym, mbutt); /*调用readmouse函数得到新的热键位置和鼠标按钮状态*/                                                                       
          
		huashubiao(xx0, yy0);	/*在原处用异或的方式将原来的鼠标覆盖*/                                                   
		huashubiao(xm, ym);	/*在新的位置画鼠标*/	                                                        
		*mx = xm;                                                                                     
		*my = ym;                                                                                     
} 
void hnewmouse(int *mx, int *my, int *mbutt)      //只读出鼠标状态，不画出,把原来的鼠标异或

{
		int xx0=*mx;
		int yy0=*my;
		
		huashubiao(xx0,yy0)  ;
	                                                                                    
} 
