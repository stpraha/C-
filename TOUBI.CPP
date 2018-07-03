#include<stdio.h>
#include<graphics.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<io.h>
#include<bios.h>
#include"jinzhi.h"
#include<alloc.h>
#include"toubi.h"
#include"donhua.h"

#include"shubiao.h"
#include"hanzi1.h"

int toubijiemian(float money1)
{

	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"d:\\borlandC\\bgi");
	cleardevice();
	huatoubizhengtijiemian();
	huatoubiji();
	huachubiji();
	huaqianbi10();
	huaqianbi5();
	huaqianbi1();
	char a1[10];
	int sum=(int)money1;
	int k;
	sprintf(a1,"%d",sum);
	settextstyle(0,0,2);
	settextjustify(0,2);
	outtextxy(150,76,a1);
	hanzi("请开始投币",250,185,20,1,1,RED);
	k=toubi(sum);
	
	if(k==1)
	{
	closegraph();
		return 5;
	}
	else
	{
	closegraph();
		return 0;
	}
	closegraph();


}


/*画整体界面*/
void huatoubizhengtijiemian()
{

	int d1[]={2,2,636,1,636,476,1,476,2,2};
	int d2[]={46,48,568,48,568,398,46,398,46,48};
	setbkcolor(7);
	setviewport(1,1,639,479,1);
	setcolor(RED);
	setfillstyle(11,6);
	fillpoly(4,d1);
	setviewport(10,10,630,470,1);
	clearviewport();
	setcolor(RED);
	setfillstyle(1,WHITE);
	fillpoly(4,d2);
	hanzi("投币找零",250,16,30,2,2,RED);
	hanzi("需投入",65,76,20,1,1,RED);
	hanzi("元",220,76,20,1,1,RED);
	hanzi("已投入",360,76,20,1,1,RED) ;
	hanzi("元",500,76,20,1,1,RED);
	setcolor(RED);
	setfillstyle(1,7);
	rectangle(450,410,570,450);
	floodfill(460,430,RED);
	hanzi("返回主菜单",460,420,20,1,1,RED);

}



/*画投币机*/
void huatoubiji()
{


	setcolor(BLACK) ;
	setfillstyle(1,11);
	line(76,115,68,224);
	line(212,115,204,224);
	line(76,115,212,115);
	line(68,224,204,224);
	floodfill(80,200,BLACK);

	setcolor(YELLOW);
	setfillstyle(1,11);
	line(68,224,204,224);
	line(204,224,213,250);
	line(213,250,68,250);
	line(68,250,68,224);
	floodfill(100,230,YELLOW);
	line(213,115,225,140);
	line(225,140,213,250);
	line(213,115,205,225);
	floodfill(215,204,YELLOW);

	setcolor(5);
	setfillstyle(1,7);
	line(105,140,162,140);
	line(162,140,157,183);
	line(157,183,112,183);
	line(112,183,105,140);
	floodfill(127,164,5);

	setfillstyle(1,8);
	line(100,214,105,140);
	line(100,214,112,183);
	floodfill(106,183,5);
	line(169,214,162,140);
	line(169,214,157,183);
	floodfill(163,185,5);

	setcolor(5);
	setfillstyle(6,BLACK);

	line(108,190,160,190);

	floodfill(124,188,5);
	setfillstyle(1,7);
	line(100,214,169,214);
	floodfill(130,202,5);
	setcolor(RED);
	line(122,183,118,190);
	line(132,183,128,190);
	line(142,183,138,190);
	line(152,183,148,190);
	hanzi("投币机",103,260,30,1,1,RED);


}


/*画出币机*/
void huachubiji()
{

	int size;
	void *buffer;
	setcolor(BLUE);
	setfillstyle(1,7);
	line(362,147,495,147);
	line(495,147,495,247);
	line(495,247,362,247);
	line(362,247,362,147);
	floodfill(424,170,BLUE);

	setcolor(3);
	setfillstyle(1,11);
	line(355,119,362,146);
	line(355,119,488,119);
	line(488,119,495,146);
	line(362,146,495,146);
	floodfill(426,137,3);

	setcolor(3);
	setfillstyle(1,11);
	line(353,220,355,119);
	line(353,220,361,247);
	line(355,119,361,147);
	line(361,147,361,247);
	floodfill(357,220,3);

	setcolor(RED);
	line(398,181,468,181);
	setcolor(RED);
	setfillstyle(1,8)   ;
	sector(433,181,180,360,35,35);
	hanzi("出币出票机",350,260,30,1,1,RED);

}


/*.............画钱币.................*/

/*画十元纸币*/
void huaqianbi10()
{
	char b1[10];
	setcolor(BLACK);
	setfillstyle(1,BLUE);
	rectangle(113,322,147,388);
	floodfill(126,351,BLACK);
	hanzi("十",120,327,20,1,1,RED);
	hanzi("元",120,365,20,1,1,RED);
	setcolor(RED);
	settextjustify(0,2);
	settextstyle(0,0,1);
	outtextxy(123,315,"F");
	sprintf(b1,"%d",10);
	outtextxy(133,315,b1);
}

/*画五元纸币*/
void huaqianbi5()
{
	char b2[10];
	setcolor(BLACK);
	setfillstyle(1,2);
	rectangle(206,322,240,388);
	floodfill(220,361,BLACK);
	hanzi("五",215,327,20,1,1,RED);
	hanzi("元",215,365,20,1,1,RED);
	setcolor(RED);
	settextjustify(0,2);
	settextstyle(0,0,1);
	outtextxy(216,315,"F");
	sprintf(b2,"%d",5);
	outtextxy(230,315,b2);
 }
	/*一元硬币*/
void huaqianbi1()
{	char b3[10];
	setcolor(BLACK);
	setfillstyle(1,YELLOW);
	rectangle(308,322,342,388);
	floodfill(319,375,BLACK);
	setcolor(BLACK)  ;
	setfillstyle(1,WHITE);
	sector(325,355,0,360,13,13);
	line(325,355,312,355);
	hanzi("一",352,340,10,1,1,RED);
	hanzi("元",352,360,10,1,1,RED);
	setcolor(RED);
	settextjustify(0,2);
	settextstyle(0,0,1);
	outtextxy(318,315,"F");
	sprintf(b3,"%d",1);
	outtextxy(330,315,b3);

}

int   toubi(int sum)
{
	static int touru=0;
	int ky;
	int k;
	setcolor(RED);
	settextstyle(0,0,2);
	char a2[10];
	sprintf(a2,"%d",touru);
	outtextxy(460,76,a2);
	int mouse_x=0,mouse_y=0,mouseclick=0;
	cursor(mouse_x,mouse_y);
	while(1)
	{
		newmouse(&mouse_x,&mouse_y,&mouseclick);
		/*鼠标特效*/ /*texiao*/
		//shiyuan
		if(113<mouse_x&&mouse_x<147&&mouse_y>322&&mouse_y<388)/*十元特效*/
		{
			setcolor(YELLOW);
			setfillstyle(1,11);
			rectangle(113,322,147,388);
			floodfill(126,351,YELLOW);
			hanzi("十",120,327,20,1,1,RED);
			hanzi("元",120,365,20,1,1,RED);


		}
		else
		{
			setcolor(BLACK);
			setfillstyle(1,BLUE);
			rectangle(113,322,147,388);
			floodfill(126,351,BLACK);
			hanzi("十",120,327,20,1,1,RED);
			hanzi("元",120,365,20,1,1,RED);

		}
		//5yuan
		if(mouse_x>206&&mouse_x<240&&mouse_y>322&&mouse_y<388)/*五元特效*/
		{
			setcolor(YELLOW);
			setfillstyle(1,11);
			rectangle(206,322,240,388);
			floodfill(220,361,YELLOW);
			hanzi("五",215,327,20,1,1,RED);
			hanzi("元",215,365,20,1,1,RED);


		}
		else
		{
			setcolor(BLACK);
			setfillstyle(1,2);
			rectangle(206,322,240,388);
			floodfill(220,361,BLACK);
			hanzi("五",215,327,20,1,1,RED);
			hanzi("元",215,365,20,1,1,RED);

		}
		//yiyuan
		if(mouse_x>308&&mouse_x<342&&mouse_y>322&&mouse_y<388)/*一元特效*/
		{
			setcolor(RED);
			setfillstyle(1,11);
			rectangle(308,322,342,388);
			floodfill(319,375,RED);
			setcolor(BLACK)  ;
			setfillstyle(1,WHITE);
			sector(325,355,0,360,13,13);
			line(325,355,312,355);
			hanzi("一",352,340,10,1,1,RED);
			hanzi("元",352,360,10,1,1,RED);

		}
		else
		{

			setcolor(BLACK);
			setfillstyle(1,YELLOW);
			rectangle(308,322,342,388);
			floodfill(319,375,BLACK);
			setcolor(BLACK)  ;
			setfillstyle(1,WHITE);
			sector(325,355,0,360,13,13);
			line(325,355,312,355);
			hanzi("一",352,340,10,1,1,RED);
			hanzi("元",352,360,10,1,1,RED);


		}
		/*鼠标确认投币*/
		//shubiao queren toubi
		if(113<mouse_x&&mouse_x<147&&mouse_y>322&&mouse_y<388&&mouseclick!=0)
		{
			touru+=10;
			k=toubi10(sum,touru);
			if(k==0)
			{
				touru=0;
				return 1;
			}

		}
		if(mouse_x>206&&mouse_x<240&&mouse_y>322&&mouse_y<388&&mouseclick!=0)
		{
			touru+=5;
			k=toubi5(sum,touru);
			if(k==0)
			{
				touru=0;
				return 1;
			}

		}
		if(mouse_x>308&&mouse_x<342&&mouse_y>322&&mouse_y<388&&mouseclick!=0)

		{
			touru+=1;
			k=toubi1(sum,touru);
			if(k==0)
			{
				touru=0;
				return 1;
			}

		}

		//jianpan toubi
		if(kbhit())
		{

		ky= bioskey(0);
		switch(ky)
		{

			case F1:
					touru+=1;
					k=toubi1(sum,touru);
					if(k==1)
					{
						break;
					}
					else
					{
						touru=0;
						return 1;
					}


			case  F5:
					touru+=5;
					k=toubi5(sum,touru);
					if(k==1)
					{
						break;
					}
					else
					{
						touru=0;
						return 1;
					}
			case F10:
					touru+=10;
					k=toubi10(sum,touru);
					if(k==1)
					{
						break;
					}
					else
					{
						touru=0;
						return 1;
					}

			default:
				setfillstyle(1,WHITE);
				bar(240,180,350,270);
				setcolor(RED);
				settextjustify(0,2);
				hanzi("按键错误",250,185,20,1,1,RED) ;
				hanzi("请重新投币",240,210,20,1,1,RED) ;
				delay(1000);
				break;


		}
		}
		/*fanhui zhucaidan*/
		if(mouse_x>450&&mouse_x<570&&mouse_y>410&&mouse_y<450)
		{
			setcolor(YELLOW);
			setfillstyle(1,11);
			rectangle(450,410,570,450);
			floodfill(460,430,YELLOW);
			hanzi("返回主菜单",460,420,20,1,1,RED);
			delay(100);
		}
		else
		{
			setcolor(RED);
			setfillstyle(1,7);
			rectangle(450,410,570,450);
			floodfill(460,430,RED);
			hanzi("返回主菜单",460,420,20,1,1,RED);
		}
		if(mouse_x>450&&mouse_x<570&&mouse_y>410&&mouse_y<450&&mouseclick!=0)
		{
			setcolor(YELLOW);
			setfillstyle(1,11);
			rectangle(450,410,570,450);
			floodfill(460,430,YELLOW);
			hanzi("返回主菜单",460,420,20,1,1,RED);
			return 0;
		}

	}


}

int toubi10(int sum,int touru)
{
	 char a2[10];
	 int zhaolin;
	 int yizhaolin=0;
	 int d1,d2;
	 char a1[10];
	 char a3[10];
	 int i=0;
	 int j=0;
	 
	 toubidonhua10() ;
	 delay(1000);
	 setfillstyle(1,WHITE);
	 bar(450,70,490,100);
	 setcolor(RED);
	 settextstyle(0,0,2);
	 settextjustify(0,2);
	 sprintf(a2,"%d",touru);
	 outtextxy(460,76,a2);
	 setfillstyle(1,WHITE);
	 bar(240,180,350,270);
	 setcolor(RED);
	 settextjustify(0,2);
	 hanzi("投十元成功",250,185,20,1,1,RED) ;
	 delay(1000);
	 if(touru>sum)
	 {
	   /*ti shi kaishi zhaolin */
	   setfillstyle(1,WHITE);
	   bar(240,180,350,240);
	   setcolor(RED);
	   settextjustify(0,2);
	   delay(500);
	   hanzi("钱币已够",250,185,20,1,1,RED);
	   hanzi("开始找零",250,210,20,1,1,RED);
	   delay(1000);
	   

	   zhaolin=touru-sum;
	   /*toubi zugou  hou kaishi zhaolin qianshu*/
	   setfillstyle(1,WHITE)   ;
	   bar(60,70,250,100);
	   hanzi("需找零",65,76,20,1,1,RED);
	   hanzi("元",220,76,20,1,1,RED);
	   sprintf(a1,"%d",zhaolin);
	   setcolor(RED);
	   settextstyle(0,0,2);
	   settextjustify(0,2);
	   outtextxy(150,76,a1);
	   setfillstyle(1,WHITE);
	   bar(350,70,530,100) ;
	   hanzi("已找零",360,76,20,1,1,RED);
	   hanzi("元",500,76,20,1,1,RED);
	   sprintf(a3,"%d",0);
	   setcolor(RED);
	   settextstyle(0,0,2);
	   settextjustify(0,2);
	   outtextxy(460,76,a3);


	   if(zhaolin>=5)
	   {

			d1=zhaolin%5;
			d2=zhaolin/5;
			
			
			for(i=0;i<d1;i++)
			{

				zhaolindonhua1();
				yizhaolin+=1;
				/*dontai shuchu yitou yinbi*/


				setfillstyle(1,WHITE);
				bar(430,70,490,100);

				setcolor(RED);
				settextstyle(0,0,2);
				settextjustify(0,2)  ;
				sprintf(a3,"%d",yizhaolin);
				outtextxy(450,76,a3);

			}
			
			for(j=0;j<d2;j++)
			{
				zhaolindonhua5();
				yizhaolin +=5;
				/*dontai shuchu yizhao qianbi*/
				setfillstyle(1,WHITE);
				bar(430,70,490,100);
		
				setcolor(RED);
				settextjustify(0,2);
				settextstyle(0,0,2);
				sprintf(a3,"%d",yizhaolin);
				outtextxy(450,76,a3);
			}
			

		}
		else
		{

			d1=zhaolin;
			for (i=0;i<d1;i++)
			{
				zhaolindonhua1();
				yizhaolin+=1 ;
				/*dontai shuchu yitou yinbi*/


				setfillstyle(1,WHITE);
				bar(430,70,490,100);

				setcolor(RED);
				settextstyle(0,0,2);
				settextjustify(0,2);
				sprintf(a3,"%d",yizhaolin);
				outtextxy(450,76,a3);

			}
	   }
	   /*tishi kaishi chupiao*/
	   
	   setfillstyle(1,WHITE);
	   bar(240,180,350,270);
	   setcolor(RED);
	   settextjustify(0,2);

	   hanzi("开始出票",250,210,20,1,1,RED);
	   delay(1000);

	   chuchepiao();        /*qiangoujiuchupiao*/
	   /*tishi goupiao chengon*/
	   setfillstyle(1,WHITE);
	   bar(240,180,350,270);
	   setcolor(RED);
	
	   settextjustify(0,2)  ;
	   delay(500);
	   hanzi("购票成功",230,185,20,1,1,RED)  ;
	   hanzi("欢迎再次使用",230,210,20,1,1,RED);
	   setfillstyle(1,WHITE);
	   bar(240,180,350,270);
	   hanzi("请稍等",230,185,30,2,2,RED);
	   hanzi("列车马上就到",230,210,30,2,2,RED);
	  
	   delay(2000);
	   return 0;


	 }
	 if(touru==sum)
	 {
	   /*tishi kaishi chupiao*/
	   setfillstyle(1,WHITE);
	   bar(240,180,350,270);/*zhonjian tishi bankuai*/
	   setcolor(RED);
	   
	   delay(500);
	   hanzi("钱币已够",250,185,20,1,1,RED);
	   hanzi("开始出票",250,210,20,1,1,RED)  ;
	   delay(1000);
	   chuchepiao()  ;
	   /*tishi goupiao chengon*/
	   setfillstyle(1,WHITE);
	   bar(240,180,350,270);
	   setcolor(RED);
	   settextjustify(0,2);
	   hanzi("购票成功",230,185,20,1,1,RED) ;
	   hanzi("欢迎再次使用",230,210,20,1,1,RED);
	    setfillstyle(1,WHITE);
	   bar(240,180,350,270);
	   hanzi("请稍等",230,185,20,1,1,RED) ;
	   hanzi("列车马上就到",230,210,20,1,1,RED);
	   delay(2000);
	   return 0;

	 }
	 if(touru<sum)
	 {
			setfillstyle(1,WHITE);
			bar(240,180,350,270);
			setcolor(RED);
			settextjustify(0,2);
			delay(500);
			hanzi("请继续投币",240,185,20,1,1,RED) ;
			delay(1000);

		    return 1;

	 }

}


int toubi5(int sum,int touru)
{
			char a2[10];
			int zhaolin;
			int yizhaolin=0;
			int d1;
			char a1[10];
			char a3[10];
			int i=0;
			toubidonhua5();
			delay(1000);
			setfillstyle(1,WHITE);
			bar(450,70,490,100);
	
			setcolor(RED);
			settextstyle(0,0,2);
			settextjustify(0,2) ;
			sprintf(a2,"%d",touru);
			outtextxy(460,76,a2);
			setfillstyle(1,WHITE);
			bar(240,180,350,270);
			setcolor(RED);
			settextjustify(0,2);
			hanzi("投五元成功",250,185,20,1,1,RED) ;
			delay(1000);
			 
			 if(touru>sum)
			{
			/*ti shi kaishi zhaolin */
			setfillstyle(1,WHITE);
			bar(240,180,350,240);
			setcolor(RED);
			settextjustify(0,2);
			delay(500);
			hanzi("钱币已够",250,185,20,1,1,RED);
			hanzi("开始找零",250,210,20,1,1,RED);
			delay(1000);
			
			
			zhaolin=touru-sum;
			/*toubi zugou  hou kaishi zhaolin qianshu*/
			setfillstyle(1,WHITE)   ;
			bar(60,70,250,100);
			hanzi("需找零",65,76,20,1,1,RED);
			hanzi("元",220,76,20,1,1,RED);
			sprintf(a1,"%d",zhaolin);
			setcolor(RED);
			settextstyle(0,0,2);
			settextjustify(0,2);
			outtextxy(150,76,a1);
			setfillstyle(1,WHITE);
			bar(350,70,530,100) ;
			hanzi("已找零",360,76,20,1,1,RED);
			hanzi("元",500,76,20,1,1,RED);
			sprintf(a3,"%d",0);
			setcolor(RED);
			settextstyle(0,0,2);
			settextjustify(0,2);
			outtextxy(460,76,a3);
			
			
			if(zhaolin>=5)
			{
			
					d1=zhaolin%5;
					if(d1!=0)
					{
						for(i=0;i<d1;i++)
						{
			
							zhaolindonhua1();
							yizhaolin+=1;
							/*dontai shuchu yitou yinbi*/
			
			
							setfillstyle(1,WHITE);
							bar(430,70,490,100);
			
							setcolor(RED);
							settextstyle(0,0,2);
							settextjustify(0,2)  ;
							sprintf(a3,"%d",yizhaolin);
							outtextxy(450,76,a3);
			
						}
					}
			
					zhaolindonhua5();
					yizhaolin +=5;
					/*dontai shuchu yizhao qianbi*/
			
			
					setfillstyle(1,WHITE);
					bar(430,70,490,100);
			
					setcolor(RED);
					settextjustify(0,2);
					settextstyle(0,0,2);
					sprintf(a3,"%d",yizhaolin);
					outtextxy(450,76,a3);
			
			
			
			}
			else
			{
			
					d1=zhaolin;
					for (i=0;i<d1;i++)
					{
						zhaolindonhua1();
						yizhaolin+=1 ;
						/*dontai shuchu yitou yinbi*/
			
			
						setfillstyle(1,WHITE);
						bar(430,70,490,100);
			
						setcolor(RED);
						settextstyle(0,0,2);
						settextjustify(0,2);
						sprintf(a3,"%d",yizhaolin);
						outtextxy(450,76,a3);
			
					}
			}
			/*tishi kaishi chupiao*/
			
			setfillstyle(1,WHITE);
			bar(240,180,350,270);
			setcolor(RED);
			settextjustify(0,2);
			
			hanzi("开始出票",250,210,20,1,1,RED);
			delay(1000);
			
			chuchepiao();        /*qiangoujiuchupiao*/
			/*tishi goupiao chengon*/
			setfillstyle(1,WHITE);
			bar(240,180,350,270);
			setcolor(RED);
			
			settextjustify(0,2)  ;
			delay(500);
			hanzi("购票成功",230,185,20,1,1,RED)  ;
			hanzi("欢迎再次使用",230,210,20,1,1,RED);
			setfillstyle(1,WHITE);
			bar(240,180,350,270);
			hanzi("请稍等",230,185,20,1,1,RED) ;
			hanzi("列车马上就到",230,210,20,1,1,RED);
			delay(2000);
			return 0;
			
			
			}
			if(touru==sum)
			{
			/*tishi kaishi chupiao*/
			setfillstyle(1,WHITE);
			bar(240,180,350,270);/*zhonjian tishi bankuai*/
			setcolor(RED);
			
			delay(500);
			hanzi("钱币已够",250,185,20,1,1,RED);
			hanzi("开始出票",250,210,20,1,1,RED)  ;
			delay(1000);
			chuchepiao()  ;
			/*tishi goupiao chengon*/
			setfillstyle(1,WHITE);
			bar(240,180,350,270);
			setcolor(RED);
			settextjustify(0,2);
			hanzi("购票成功",230,185,20,1,1,RED) ;
			hanzi("欢迎再次使用",230,210,20,1,1,RED);
			setfillstyle(1,WHITE);
			bar(240,180,350,270);
			hanzi("请稍等",230,185,20,1,1,RED)  ;
			hanzi("列车马上就到",230,210,20,1,1,RED);
			delay(2000);
			return 0;
			
			}
			if(touru<sum)
			{
					setfillstyle(1,WHITE);
					bar(240,180,350,270);
					setcolor(RED);
					settextjustify(0,2);
					delay(500);
					hanzi("请继续投币",240,185,20,1,1,RED) ;
					delay(1000);
			
					return 1;
			
			}
			
}


int toubi1(int sum,int touru)
{
			char a2[10];
			int zhaolin;
			int yizhaolin=0;
			int d1;
			char a1[10];
			char a3[10];
			int i=0;
			toubidonhua1();
			delay(1000);
			setfillstyle(1,WHITE);
			bar(450,70,490,100);
			setcolor(RED);
			settextstyle(0,0,2);
			settextjustify(0,2)  ;
			sprintf(a2,"%d",touru);
			outtextxy(460,76,a2);
			setfillstyle(1,WHITE);
			bar(240,180,350,270);
			setcolor(RED);
			settextjustify(0,2);
			hanzi("投一元成功",250,185,20,1,1,RED);
            delay(1000);
			 if(touru>sum)
			{
			/*ti shi kaishi zhaolin */
			setfillstyle(1,WHITE);
			bar(240,180,350,240);
			setcolor(RED);
			settextjustify(0,2);
			delay(500);
			hanzi("钱币已够",250,185,20,1,1,RED);
			hanzi("开始找零",250,210,20,1,1,RED);
			
			delay(1000);
			zhaolin=touru-sum;
			/*toubi zugou  hou kaishi zhaolin qianshu*/
			setfillstyle(1,WHITE)   ;
			bar(60,70,250,100);
			hanzi("需找零",65,76,20,1,1,RED);
			hanzi("元",220,76,20,1,1,RED);
			sprintf(a1,"%d",zhaolin);
			setcolor(RED);
			settextstyle(0,0,2);
			settextjustify(0,2);
			outtextxy(150,76,a1);
			setfillstyle(1,WHITE);
			bar(350,70,530,100) ;
			hanzi("已找零",360,76,20,1,1,RED);
			hanzi("元",500,76,20,1,1,RED);
			sprintf(a3,"%d",0);
			setcolor(RED);
			settextstyle(0,0,2);
			settextjustify(0,2);
			outtextxy(460,76,a3);
			
			
			if(zhaolin>=5)
			{
			
					d1=zhaolin%5;
					if(d1!=0)
					{
						for(i=0;i<d1;i++)
						{
			
							zhaolindonhua1();
							yizhaolin+=1;
							/*dontai shuchu yitou yinbi*/
			
			
							setfillstyle(1,WHITE);
							bar(430,70,490,100);
			
							setcolor(RED);
							settextstyle(0,0,2);
							settextjustify(0,2)  ;
							sprintf(a3,"%d",yizhaolin);
							outtextxy(450,76,a3);
			
						}
					}
			
					zhaolindonhua5();
					yizhaolin +=5;
					/*dontai shuchu yizhao qianbi*/
			
			
					setfillstyle(1,WHITE);
					bar(430,70,490,100);
			
					setcolor(RED);
					settextjustify(0,2);
					settextstyle(0,0,2);
					sprintf(a3,"%d",yizhaolin);
					outtextxy(450,76,a3);
			
			
			
			}
			else
			{
			
					d1=zhaolin;
					for (i=0;i<d1;i++)
					{
						zhaolindonhua1();
						yizhaolin+=1 ;
						/*dontai shuchu yitou yinbi*/
			
			
						setfillstyle(1,WHITE);
						bar(430,70,490,100);
			
						setcolor(RED);
						settextstyle(0,0,2);
						settextjustify(0,2);
						sprintf(a3,"%d",yizhaolin);
						outtextxy(450,76,a3);
			
					}
			}
			/*tishi kaishi chupiao*/
			
			setfillstyle(1,WHITE);
			bar(240,180,350,270);
			setcolor(RED);
			settextjustify(0,2);
			hanzi("开始出票",250,210,20,1,1,RED);
			delay(1000);
			chuchepiao();        /*qiangoujiuchupiao*/
			/*tishi goupiao chengon*/
			setfillstyle(1,WHITE);
			bar(240,180,350,270);
			setcolor(RED);
			settextjustify(0,2)  ;
			delay(500);
			hanzi("购票成功",230,185,20,1,1,RED)  ;
			hanzi("欢迎再次使用",230,210,20,1,1,RED);
			delay(1000); setfillstyle(1,WHITE);
			setfillstyle(1,WHITE);
			bar(240,180,350,270);
			hanzi("请稍等",230,185,20,1,1,RED);
			hanzi("列车马上就到",230,210,20,1,1,RED);
			delay(2000);
			return 0;
			
			
			}
			if(touru==sum)
			{
			/*tishi kaishi chupiao*/
			setfillstyle(1,WHITE);
			bar(240,180,350,270);/*zhonjian tishi bankuai*/
			setcolor(RED);
			
			delay(500);
			hanzi("钱币已够",250,185,20,1,1,RED);
			hanzi("开始出票",250,210,20,1,1,RED)  ;
			delay(1000);
			delay(1000);
			chuchepiao()  ;
			/*tishi goupiao chengon*/
			setfillstyle(1,WHITE);
			bar(240,180,350,270);
			setcolor(RED);
			settextjustify(0,2);
			hanzi("购票成功",230,185,20,1,1,RED) ;
			hanzi("欢迎再次使用",230,210,20,1,1 ,RED);
			setfillstyle(1,WHITE);
			bar(240,180,350,270);
			hanzi("请稍等",230,185,20,1,1,RED);
			hanzi("列车马上就到",230,210,20,1,1,RED);
			
			delay(1000);
			return 0;
			
			}
			if(touru<sum)
			{
					setfillstyle(1,WHITE);
					bar(240,180,350,270);
					setcolor(RED);
					settextjustify(0,2);
					delay(500);
					hanzi("请继续投币",240,185,20,1,1,RED) ;
					delay(1000);
			
					return 1;
			
			}
			
}


void chuchepiao()
{
	int miny=141;
	int size1,size2,size3,size4;   /*size4 shichepiao*/
	void *buffer1,*buffer2,*buffer3,*buffer4;
	size1=imagesize(400,300,450,380);
	buffer1=malloc(size1);
	getimage(400,300,450,380,buffer1);
	setfillstyle(1,11);
	bar(400,300,450,380);
	hanzi("车",415,310,20,1,1,RED);
	hanzi("票",415,340,20,1,1,RED);
	
	size4=imagesize(400,300,450,380);/*chepiaotuxiang*/
	buffer4=malloc(size4);
	getimage(400,300,450,380,buffer4);

	putimage(400,300,buffer1,COPY_PUT)  ;
	size2=imagesize(350,110,500,350); /*da beijing*/
	buffer2=malloc(size2);
	getimage(350,110,500,350,buffer2);
	size3=imagesize(398,141,468,181);    /*xiaobeijing*/
	buffer3=malloc(size3);
	getimage(398,141,468,181,buffer3);
	while(miny<261)
	{

		putimage(410,miny,buffer4,COPY_PUT) ;
		putimage(398,141,buffer3,COPY_PUT);
		delay(200);
		putimage(350,110,buffer2,COPY_PUT);
		delay(200);
		miny+=20;


	}
	putimage(350,110,buffer2,COPY_PUT);
	free(buffer1);
	free(buffer2);
	free(buffer3);
	free(buffer4);

}


