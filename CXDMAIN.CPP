#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include"caidan.h"
#include"toubi.h"
#include"hanzi1.h"
#include"donhua.h"

void welcome(void);
int jinzhan();
int goupiaojiemian(int z,float *money1,int *ticketnum);
void chenche();
int changestart();
void chuzhan();
void shuomin();
int code();



void main()
{
       //	int gdriver=DETECT,gmode;
      //	initgraph(&gdriver,&gmode,"D:\\borlandC\\bgi");
	int flag=0;
	int z=0;
	float money1;
	int ticketnum1=1;
	 welcome();
	while(1)
	{
		if(flag==0)
		{

			  flag=caidan();
			   //	flag=5;
		}
		if(flag==5)
		{
			jinzhan();
			flag=7;//跳转到乘车模拟
		}
		if(flag==3)
		{
			int mo=0;
			mo=code();
			if(mo==1)
			{
				z=changestart();
				if(z>20||z<0)
				{
					z=0;
				}
				flag=1;//跳转到选站界面
			}
			else
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			flag=goupiaojiemian(z,&money1,&ticketnum1);//FLAG可以为3  0   10
		}
		/*if(flag==4)
		{
			printf("%3f",money1);
			getch();
			flag=7;//跳转到乘车模拟
		}*/
		if(flag==7)
		{
			chenche();
			flag=6;//跳转到出站动画
		}
		if(flag==6)
		{
			chuzhan();
			flag=0;//出站完毕返回主菜单
		}
		if(flag==2)
		{
			shuomin();
			flag=0;
		}
		if(flag==10)
		{
			flag=toubijiemian(money1);

		}
	}
}