#include"goupiaoj.h"

struct route
{
	int x;
	int y;
	char name[20];
	char code[20];
};

int goupiaojiemian(int z,float *money1,int *ticketnums)
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"D:\\borlandC\\bgi");

	cleardevice();
	
	struct route zh[18]={{80,100,"寝室站","a"},
				{150,120,"西五站","b"},
				{180,170,"韵苑食堂站","c"},
				{180,250,"科技楼站","d"},
				{220,280,"南一楼站","e"},
				{300,290,"西十二站","f"},
				{330,320,"东小门站","g"},
				{340,380,"中操站","h"},
				{310,440,"西一食堂站","i"},
				{120,450,"东九站","j"},
				{170,430,"东十二站","k"},
				{140,370,"百景园站","l"},
				{200,330,"集贸站","m"},
				{220,280,"南一楼站","n"},
				{260,220,"西小门站","o"},
				{300,200,"南三门站","p"},
				{350,170,"东园食堂站","q"},
				{360,120,"澡堂站","r"}};
	struct route *p;
	
	int mouse_x=0,mouse_y=0, mouseclick=0; 
	float money=0;
	char *state1="中途退出";
	char *state2="进入购票";
	int flag=0;//定义FLAG，使选站后才能点确定
	int forp;//将选站后的站号传递出来用于写入文本文件
	int flag2=0;//用于选择线路后的重新绘线路
	
	cursor(mouse_x,mouse_y);
	int ticnum=1;//票数
	
	drawjiemian(z);
	
	for(;;)
	{
		mouseclick=0;
		newmouse(&mouse_x,&mouse_y,&mouseclick);//鼠标
		buttonclick(mouse_x,mouse_y,mouseclick);//实现惦记
 		stationchoose(mouse_x,mouse_y,mouseclick,&flag2,&money,z,&flag,&forp,ticnum);//实现选站
		routechoose(&flag2,mouse_x,mouse_y,mouseclick);//实现选择路线
		ticketnum(mouse_x,mouse_y,mouseclick,&ticnum,&money);//实现票数加减
		p=zh+forp;
		//实现改站
		if(540<mouse_x&&mouse_x<630&&60<mouse_y&&mouse_y<90&&mouseclick)
		{
			buttondown(558,60,630,90);
			puts12(570,63,"更改",RED,2,2);
			delay(100);
			closegraph();
			return 3;//跳转到改出发站界面
		}
        //退出并保存
		if(310<mouse_x&&mouse_x<400&&10<mouse_y&&mouse_y<50&&mouseclick)
		{
			printf("%d",forp);
			writedata(p->name);
			writedata(state1);			
			writedata(" ");	
			delay(100);
			return 0;//返回到主菜单
		}
		//实现传递
		if(210<mouse_x&&mouse_x<300&&10<mouse_y&&mouse_y<50&&mouseclick&&flag==1)
		{
			*money1=money;
			*ticketnums=ticnum;
			writedata(p->name);
			writedata(state2);
			writedata(" ");
			delay(100);
			closegraph();
			return 10;//跳转到投币界面
		}
	}
}

void drawjiemian(int z)
{
	struct route zh[18]={{80,100,"寝室站","a"},
				{150,120,"西五站","b"},
				{180,170,"韵苑食堂站","c"},
				{180,250,"科技楼站","d"},
				{220,280,"南一楼站","e"},
				{300,290,"西十二站","f"},
				{330,320,"东小门站","g"},
				{340,380,"中操站","h"},
				{310,440,"西一食堂站","i"},
				{120,450,"东九站","j"},
				{170,430,"东十二站","k"},
				{140,370,"百景园站","l"},
				{200,330,"集贸站","m"},
				{220,280,"南一楼站","n"},
				{260,220,"西小门站","o"},
				{300,200,"南三门站","p"},
				{350,170,"东园食堂站","q"},
				{360,120,"澡堂站","r"}};

	int i=2,j=2;
	setbkcolor(LIGHTBLUE);
    //画出按钮及上面的字
	button(10,10,100,50);
	button(110,10,200,50);
	button(210,10,300,50);
	button(310,10,400,50);
	button(558,60,630,90);
	puts12(12,13,"一号线",RED,2,2);
	puts12(112,13,"二号线",RED,2,2);
	puts12(212,13,"确定",RED,2,2);
	puts12(312,13,"退出",RED,2,2);
	puts12(570,63,"更改",RED,2,2);
	//显示时间
	showtime();

	struct route *p;
	//画出站点
	for(p=zh;p<zh+18;p++)
	{
		station(p->x,p->y);
	}
	//画出一号线
	setlinestyle(0,0,i);
	setcolor(RED);
	moveto(80,100);
	for(p=zh;p<zh+9;p++)
	{
		lineto(p->x,p->y);
	}             
	//画出二号线
	setlinestyle(0,0,j);
	setcolor(BROWN);
	moveto(120,450);
	for(p=zh+9;p<zh+18;p++)
	{
		lineto(p->x,p->y);
	}                  
	//画出大站
	stationb(220,280);
	//画出边框
	setlinestyle(0,0,3);
	setcolor(MAGENTA);
	moveto(420,0);
	lineto(420,500);
	moveto(0,70);
	lineto(420,70);
	moveto(420,100);
	lineto(640,100);
	
	//画出张数三角
	setcolor(RED);
	moveto(490,245);
	lineto(510,230);
	lineto(510,260);
	lineto(490,245);
	setfillstyle(1,WHITE);
	floodfill(495,245,RED);
	moveto(605,245);
	lineto(585,230);
	lineto(585,260);
	lineto(605,245);
	floodfill(600,245,RED);
	
	//画出信息
	p=zh+z;
	puts12(455,8,"当前车站",RED,3,3);
	puts12(430,115,"从",RED,2,2);
	puts12(430,151,"到",RED,2,2);
	puts12(430,60,p->name,YELLOW,2,2);
	puts12(460,115,p->name,YELLOW,2,2);
	puts12(430,193,"的票价为",RED,2,2);
	puts12(580,193,"元",RED,2,2);
	puts12(430,234,"张数",RED,2,2);
	//写出站名和键盘代表的符号
	for(p=zh;p<zh+4;p++)
	{
		puts12(p->x-70,p->y-5,p->name,RED,1,1);
		outtextxy(p->x+6,p->y-5,p->code);
	}
	for(p=zh+5;p<zh+9;p++)
	{
		puts12(p->x-70,p->y-5,p->name,RED,1,1); 
		outtextxy(p->x+6,p->y-5,p->code);
	}
	for(p=zh+9;p<zh+13;p++)
	{
		puts12(p->x-70,p->y-5,p->name,GREEN,1,1);
		outtextxy(p->x+6,p->y-5,p->code);
	}
	for(p=zh+14;p<zh+18;p++)
	{
		puts12(p->x+20,p->y-5,p->name,GREEN,1,1);
		outtextxy(p->x+6,p->y-5,p->code);
	}
	for(p=zh+13;p<zh+14;p++)
	{
		puts16(p->x-80,p->y-5,p->name,YELLOW,1,1);
	}
	//插图
	chatu(423,269,0.9,"D:\\BORLANDC\\lala1l\\PICT\\LZ16.DAT");
}

void buttonclick(int mouse_x,int mouse_y,int mouseclick)
{		
	//实现点击按钮效果/*******************每次选择按钮都重画四个按钮*****/
	if(10<mouse_x&&mouse_x<100&&10<mouse_y&&mouse_y<50&&mouseclick)
	{
		buttondown(10,10,100,50);
		button(110,10,200,50);
		button(210,10,300,50);
		button(310,10,400,50);
		puts12(12,13,"一号线",RED,2,2);
		puts12(112,13,"二号线",RED,2,2);
		puts12(212,13,"确定",RED,2,2);
		puts12(312,13,"退出",RED,2,2);
	}
	if(110<mouse_x&&mouse_x<200&&10<mouse_y&&mouse_y<50&&mouseclick)
	{
		buttondown(110,10,200,50);
		button(10,10,100,50);
		button(210,10,300,50);
		button(310,10,400,50);
		puts12(12,13,"一号线",RED,2,2);
		puts12(112,13,"二号线",RED,2,2);
		puts12(212,13,"确定",RED,2,2);
		puts12(312,13,"退出",RED,2,2);
	}
	if(210<mouse_x&&mouse_x<300&&10<mouse_y&&mouse_y<50&&mouseclick)
	{
		buttondown(210,10,300,50);
		button(10,10,100,50);
		button(110,10,200,50);
		button(310,10,400,50);
		puts12(12,13,"一号线",RED,2,2);
		puts12(112,13,"二号线",RED,2,2);
		puts12(212,13,"确定",RED,2,2);
		puts12(312,13,"退出",RED,2,2);
	}
	if(310<mouse_x&&mouse_x<400&&10<mouse_y&&mouse_y<50&&mouseclick)
	{
		buttondown(310,10,400,50);
		button(10,10,100,50);
		button(110,10,200,50);
		button(210,10,300,50);
		puts12(12,13,"一号线",RED,2,2);
		puts12(112,13,"二号线",RED,2,2);
		puts12(212,13,"确定",RED,2,2);
		puts12(312,13,"退出",RED,2,2);
	}
}

void routechoose(int *flag2,int mouse_x,int mouse_y,int mouseclick)
{
	struct route zh[18]={{80,100,"寝室站","a"},
				{150,120,"西五站","b"},
				{180,170,"韵苑食堂站","c"},
				{180,250,"科技楼站","d"},
				{220,280,"南一楼站","e"},
				{300,290,"西十二站","f"},
				{330,320,"东小门站","g"},
				{340,380,"中操站","h"},
				{310,440,"西一食堂站","i"},
				{120,450,"东九站","j"},
				{170,430,"东十二站","k"},
				{140,370,"百景园站","l"},
				{200,330,"集贸站","m"},
				{220,280,"南一楼站","n"},
				{260,220,"西小门站","o"},
				{300,200,"南三门站","p"},
				{350,170,"东园食堂站","q"},
				{360,120,"澡堂站","r"}};
	struct route *p;
	//实现选择路线
	if(10<mouse_x&&mouse_x<100&&10<mouse_y&&mouse_y<50&&mouseclick)
	{
		*flag2=1;//使选站函数时可以重画线路
		setlinestyle(0,0,3);//用粗的蓝线覆盖原来
		setcolor(LIGHTBLUE);
		moveto(80,100);
		for(p=zh;p<zh+9;p++)
		{
			lineto(p->x,p->y);
		}             
		moveto(120,450);
		for(p=zh+9;p<zh+18;p++)
		{
			lineto(p->x,p->y);
		}       
		setlinestyle(0,0,3);//画被选线路
		setcolor(RED);
		moveto(80,100);
		for(p=zh;p<zh+9;p++)
		{
			lineto(p->x,p->y);
		}  
		setlinestyle(0,0,1);//画未被选线路
		setcolor(BROWN);
		moveto(120,450);
		for(p=zh+9;p<zh+18;p++)
		{
			lineto(p->x,p->y);
		}              
	}  
	if(110<mouse_x&&mouse_x<200&&10<mouse_y&&mouse_y<50&&mouseclick)
	{
		*flag2=1;//使选站函数时可以重画线路
		setlinestyle(0,0,3);//用粗的蓝线覆盖原来
		setcolor(LIGHTBLUE);
		moveto(80,100);
		for(p=zh;p<zh+9;p++)
		{
			lineto(p->x,p->y);
		}             
		moveto(120,450);
		for(p=zh+9;p<zh+18;p++)
		{
			lineto(p->x,p->y);
		}   
		
		setlinestyle(0,0,3);//画被选线路
		setcolor(BROWN);
		moveto(120,450);
		for(p=zh+9;p<zh+18;p++)
		{
			lineto(p->x,p->y);
		}   
		setlinestyle(0,0,1);//画未被选线路
		setcolor(RED);
		moveto(80,100);
		for(p=zh;p<zh+9;p++)
		{
			lineto(p->x,p->y);
		}      
	}    
}

void stationchoose(int mouse_x,int mouse_y,int mouseclick,int *flag2,float *money,int z,int *flag,int *forp,int ticnum)
{
	struct route zh[18]={{80,100,"寝室站","a"},
				{150,120,"西五站","b"},
				{180,170,"韵苑食堂站","c"},
				{180,250,"科技楼站","d"},
				{220,280,"南一楼站","e"},
				{300,290,"西十二站","f"},
				{330,320,"东小门站","g"},
				{340,380,"中操站","h"},
				{310,440,"西一食堂站","i"},
				{120,450,"东九站","j"},
				{170,430,"东十二站","k"},
				{140,370,"百景园站","l"},
				{200,330,"集贸站","m"},
				{220,280,"南一楼站","n"},
				{260,220,"西小门站","o"},
				{300,200,"南三门站","p"},
				{350,170,"东园食堂站","q"},
				{360,120,"澡堂站","r"}};
				
	struct route *p;	
	
	int num=0;//站编号

	char *mon;//用于显示金额的CHAR类型变量
	char *tinum;//票数，是地址所以可更改
	int dec,sign;//定义的将FLOAT转换位CHAR所需要的变量
	float moneyy;//用与接收*MONEY的植显示在屏幕上
	float ticnumm;//用于接收TICNUM并将其转化为FLOAT型用于接下来的转换和显示
	//实现鼠标选站
	if(mouseclick)
	{
		num=xuanzhan(mouse_x,mouse_y,mouseclick);
		mouseclick=0;
	}
	//实现键盘选站
	int ch;
	if(kbhit())
	{
		ch=bioskey(0);
		num=kbxuanzhan(ch);
	}

	//选站之后的刷新按钮，画出路线
	if(num!=0&&num<19)
	{
		*flag=1;//使确定按钮生效
		*forp=num-1;
		setfillstyle(1,LIGHTBLUE);//覆盖原有站点票价
		bar(460,150,640,180);
		bar(525,190,580,220);
		bar(520,230,580,260);
		*money=ticnum*calculate(num,z);//计算票价
		moneyy=*money;
		mon=fcvt(moneyy,1,&dec,&sign);//显示票价
		settextstyle(1,0,3);
		outtextxy(535,190,mon);
		if(moneyy<10)
		{
			outtextxy(546,194,".");
		}
		if(moneyy>=10)
		{
			outtextxy(561,194,".");
		}	
		ticnumm=(float)ticnum;
		tinum=fcvt(ticnumm,0,&dec,&sign);
		outtextxy(540,230,tinum);
		passroute(num,z);//画出路线
		p=zh+num-1;
		puts12(460,150,p->name,YELLOW,2,2);
		if(*flag2==1)//刷新按钮重画线路
		{
		    button(10,10,100,50);
			button(110,10,200,50);
			button(210,10,300,50);
			button(310,10,400,50);
			puts12(12,13,"一号线",RED,2,2);
			puts12(112,13,"二号线",RED,2,2);
			puts12(212,13,"确定",RED,2,2);
			puts12(312,13,"退出",RED,2,2);
			setlinestyle(0,0,3);
			setcolor(LIGHTBLUE);
			moveto(80,100);
			for(p=zh;p<zh+9;p++)
			{
				lineto(p->x,p->y);
			}             
			moveto(120,450);
			for(p=zh+9;p<zh+18;p++)
			{
				lineto(p->x,p->y);
			}       
			setlinestyle(0,0,1);
			setcolor(BROWN);
			moveto(120,450);
			for(p=zh+9;p<zh+18;p++)
			{
				lineto(p->x,p->y);
			}              
			setlinestyle(0,0,1);
			setcolor(RED);
			moveto(80,100);
			for(p=zh;p<zh+9;p++)
			{
				lineto(p->x,p->y);
			}      
			*flag2=0;
		}	
	}
}

void passroute(int num,int z)
{
	int x=num-1;
	int k=0;
	int a1[9]={80,150,180,180,220,300,330,340,310};
	int b1[9]={100,120,170,250,280,290,320,380,440};
	int a2[9]={120,170,140,200,220,260,300,350,360};
	int b2[9]={450,430,370,330,280,220,200,170,120};

	setlinestyle(0,0,1);
	setcolor(RED);
	moveto(a1[0],b1[0]);
	for(k=0;k<9;k++)
	{
		lineto(a1[k],b1[k]);
	}             
	setcolor(BROWN);
	moveto(a2[0],b2[0]);
	for(k=0;k<9;k++)
	{
		lineto(a2[k],b2[k]);
	}       
    
	setlinestyle(0,0,1);
	setcolor(GREEN);	
	if(0<=z&&z<=3)
	{
		if(0<=x&&x<=4)
		{
			moveto(a1[z],b1[z]);
			if(x>z)
			{
				for(k=z;k<=x;k++)
				{
					lineto(a1[k],b1[k]);
				}
			}
			if(z>x)
			{
				for(k=z;k>=x;k--)
				{
					lineto(a1[k],b1[k]);
				}
			}
		}
		if(5<=x&&x<=8)
		{
			moveto(a1[z],b1[z]);
			for(k=z;k<=x;k++)
			{
				lineto(a1[k],b1[k]);
			}
		}
		if(8<x&&x<13)
		{
			moveto(a1[z],b1[z]);
			for(k=z;k<5;k++)
			{
				lineto(a1[k],b1[k]);
			}
			for(k=13;k>=x;k--)
			{
				lineto(a2[k-9],b2[k-9]);
			}
		}
		if(13<x&&x<18)
		{
			moveto(a1[z],b1[z]);
			for(k=z;k<5;k++)
			{
				lineto(a1[k],b1[k]);
			}
			for(k=13;k<=x;k++)
			{
				lineto(a2[k-9],b2[k-9]);
			}
		}
	}
	if(5<=z&&z<=8)
	{
		if(0<=x&&x<=4)
		{
			moveto(a1[z],b1[z]);
			for(k=z;k>=x;k--)
			{
				lineto(a1[k],b1[k]);
			}
		}
		if(5<=x&&x<=8)
		{
			moveto(a1[z],b1[z]);
			if(z>x)
			{
				for(k=z;k>=x;k--)
				{
					lineto(a1[k],b1[k]);
				}
			}
			if(z<x)
			{
				for(k=z;k<=x;k++)
				{
					lineto(a1[k],b1[k]);
				}
			}
		}
		if(8<x&&x<13)
		{
			moveto(a1[z],b1[z]);
			for(k=z;k>=4;k--)
			{
				lineto(a1[k],b1[k]);
			}
			for(k=13;k>=x;k--)
			{
				lineto(a2[k-9],b2[k-9]);
			}
		}
		if(13<x&&x<18)
		{
			moveto(a1[z],b1[z]);
			for(k=z;k>=4;k--)
			{
				lineto(a1[k],b1[k]);
			}
			for(k=13;k<=x;k++)
			{
				lineto(a2[k-9],b2[k-9]);
			}
		}
	}
	if(9<=z&&z<=12)
	{
		if(0<=x&&x<=4)
		{
			moveto(a2[z-9],b2[z-9]);
			for(k=z;k<=13;k++)
			{
				lineto(a2[k-9],b2[k-9]);
			}
			for(k=4;k>=x;k--)
			{
				lineto(a1[k],b1[k]);
			}
		}
		if(5<=x&&x<=8)
		{
			moveto(a2[z-9],b2[z-9]);
			for(k=z;k<=13;k++)
			{
				lineto(a2[k-9],b2[k-9]);
			}
			for(k=4;k<=x;k++)
			{
				lineto(a1[k],b1[k]);
			}
		}
		if(9<=x&&x<=12)
		{
			moveto(a2[z-9],b2[z-9]);
			if(z>x)
			{	
				for(k=z;k>=x;k--)
				{
					lineto(a2[k-9],b2[k-9]);
				}
			}
			if(z<x)
			{
				for(k=z;k<=x;k++)
				{
					lineto(a2[k-9],b2[k-9]);
				}
			}
		}
		if(14<=x&&x<=17)
		{
			moveto(a2[z-9],b2[z-9]);
			for(k=z;k<=x;k++)
			{
				lineto(a2[k-9],b2[k-9]);
			}
		}
	}
	if(14<=z&&z<=17)
	{
		if(0<=x&&x<=4)
		{
			moveto(a2[z-9],b2[z-9]);
			for(k=z;k>=13;k--)
			{
				lineto(a2[k-9],b2[k-9]);
			}
			for(k=4;k>=x;k--)
			{
				lineto(a1[k],b1[k]);
			}
		}
		if(5<=x&&x<=8)
		{
			moveto(a2[z-9],b2[z-9]);
			for(k=z;k>=13;k--)
			{
				lineto(a2[k-9],b2[k-9]);
			}
			for(k=4;k<=x;k++)
			{
				lineto(a1[k],b1[k]);
			}
		}
		if(9<=x&&x<=12)
		{
			moveto(a2[z-9],b2[z-9]);
			for(k=z;k>=x;k--)
			{
				lineto(a2[k-9],b2[k-9]);
			}
		}
		if(14<=x&&x<=17)
		{
			moveto(a2[z-9],b2[z-9]);
			if(z>x)
			{
				for(k=z;k>=x;k--)
				{
					lineto(a2[k-9],b2[k-9]);
				}
			}
			if(z<x)
			{
				for(k=z;k<=x;k++)
				{
					lineto(a2[k-9],b2[k-9]);
				}
			}
		}
	}
	if(z==4||z==13)
	{
		moveto(a1[4],b1[4]);
		if(0<=x&&x<=3)
		{
			for(k=4;k>=x;k--)
			{
				lineto(a1[k],b1[k]);
			}
		}
		if(5<=x&&x<=8)
		{
			for(k=4;k<=x;k++)
			{
				lineto(a1[k],b1[k]);
			}
		}
		if(9<=x&&x<=12)
		{
			for(k=13;k>=x;k--)
			{
				lineto(a2[k-9],b2[k-9]);
			}
		}
		if(14<=x&&x<=17)
		{
			for(k=13;k<=x;k++)
			{
				lineto(a2[k-9],b2[k-9]);
			}
		}
	}
}


void ticketnum(int mouse_x,int mouse_y,int mouseclick,int *ticnum,float *money)
{
	char *mon;
	char *tinum;
	int dec,sign;
	float moneyy;//用与接收*MONEY的植显示在屏幕上
	float ticnumm;
	int k;
	float t;
	float m;
	k=*ticnum;
	t=(float)k;
	m=(*money)/t;
	int flag3;

	if(495<mouse_x&&mouse_x<510&&235<mouse_y&&mouse_y<255&&mouseclick&&k>1)
	{
		*ticnum=k-1;
		mouseclick=0;
		flag3=1;
		delay(300);
		
	}
	if(585<mouse_x&&mouse_x<600&&235<mouse_y&&mouse_y<255&&mouseclick&&k<9)
	{
		*ticnum=k+1;
		mouseclick=0;
		flag3=1;
		delay(300);
		
	}	
	if(flag3==1)
	{
		setfillstyle(1,LIGHTBLUE);
		bar(525,190,580,222);
		bar(520,230,580,260);
		ticnumm=(float)(*ticnum);
		*money=ticnumm*m;//计算票价
		moneyy=*money;
		mon=fcvt(moneyy,1,&dec,&sign);//显示票价
		settextstyle(1,0,3);
		outtextxy(535,190,mon);
		if(moneyy<10)
		{
			outtextxy(546,194,".");
		}
		if(moneyy>=10)
		{
			outtextxy(561,194,".");
		}	
		ticnumm=(float)(*ticnum);
		tinum=fcvt(ticnumm,0,&dec,&sign);
		outtextxy(540,230,tinum);
		flag3=0;
	}
}