int xuanzhan(int mouse_x,int mouse_y,int mouseclick)
{
	int a1[9]={80,150,180,180,220,300,330,340,310};
	int b1[9]={100,120,170,250,280,290,320,380,440};
	int a2[9]={120,170,140,200,220,260,300,350,360};
	int b2[9]={450,430,370,330,280,220,200,170,120};
	int i,j;
	for(i=0;i<9;i++)
	{
		if(a1[i]-4<mouse_x&&mouse_x<a1[i]+4&&b1[i]-4<mouse_y&&mouse_y<b1[i]+4&&mouseclick)
		{
			for(j=0;j<9;j++)
			{
				station(a1[j],b1[j]);
				station(a2[j],b2[j]);
				stationb(a2[4],b2[4]);
			}
			stationdown(a1[i],b1[i]);
			return i+1;		
		}
		if(a2[i]-4<mouse_x&&mouse_x<a2[i]+4&&b2[i]-4<mouse_y&&mouse_y<b2[i]+4&&mouseclick)
		{
			for(j=0;j<9;j++)
			{
				station(a1[j],b1[j]);
				station(a2[j],b2[j]);
				stationb(a2[4],b2[4]);
			}
			stationdown(a2[i],b2[i]);
			return (10+i);
		}
		if(a2[4]-8<mouse_x&&mouse_x<a2[4]+8&&b2[4]-8<mouse_y&&mouse_y<b2[4]+8&&mouseclick)
		{
			for(j=0;j<9;j++)
			{
				station(a1[j],b1[j]);
				station(a2[j],b2[j]);
			}
			stationdownb(a2[4],b2[4]);
			return 5;
		}
	}
}

int kbxuanzhan(int ch)
{
	int j=0,i=0;
	int a1[9]={80,150,180,180,220,300,330,340,310};
	int b1[9]={100,120,170,250,280,290,320,380,440};
	int a2[9]={120,170,140,200,220,260,300,350,360};
	int b2[9]={450,430,370,330,280,220,200,170,120};
	
	for(j=0;j<9;j++)
	{
		station(a1[j],b1[j]);
		station(a2[j],b2[j]);
		stationb(a2[4],b2[4]);
	}
	
	switch(ch)
	{
		case 0x1e61:
			stationdown(a1[0],b1[0]);
			i=1;
		break;

		case 0x3062:
			stationdown(a1[1],b1[1]);
			i=2;
		break;
  
		case 0x2e63:
			stationdown(a1[2],b1[2]);
			i=3;
		break;
  
		case 0x2064:
			stationdown(a1[3],b1[3]);
			i=4;
		break;
  
		case 0x1265:
			stationdown(a1[4],b1[4]);
			i=5;
		break;
  
		case 0x2166:
			stationdown(a1[5],b1[5]);
			i=6;
		break;
  
		case 0x2267:
			stationdown(a1[6],b1[6]);
			i=7;
		break;
  
		case 0x2368:
			stationdown(a1[7],b1[7]);
			i=8;
		break;
  
		case 0x1769:
			stationdown(a1[8],b1[8]);
			i=9;
		break;
  
		case 0x246a:
			stationdown(a2[0],b2[0]);
			i=10;
		break;
  
		case 0x256b:
			stationdown(a2[1],b2[1]);
			i=11;
		break;
  
		case 0x266c:
			stationdown(a2[2],b2[2]);
			i=12;
		break;
  
		case 0x326d:
			stationdown(a2[3],b2[3]);
			i=13;
		break;
		
		case 0x316e:
			stationdown(a2[4],b2[4]);
			i=14;
		break;
		
		case 0x186f:
			stationdown(a2[5],b2[5]);
			i=15;
		break;
  
		case 0x1970:
			stationdown(a2[6],b2[6]);
			i=16;
		break;
  
		case 0x1071:
			stationdown(a2[7],b2[7]);
			i=17;
		break;

		case 0x1372:
			stationdown(a2[8],b2[8]);
			i=18;
		break;
	}
	return i;
}

void button(int x1,int y1,int x2,int y2)//按钮未按下状态
{
	int WIDTH=5;
	int i;
	setfillstyle(1,LIGHTGRAY);
	bar(x1,y1,x2,y2);
	for(i=0;i<WIDTH;i++)
	{
		setcolor(WHITE);
		moveto(x1-WIDTH+i,y1-WIDTH+i);
		lineto(x2,y1-WIDTH+i);
		setcolor(YELLOW);
		moveto(x1-WIDTH+i,y1-WIDTH+i);
		lineto(x1-WIDTH+i,y2);
	}
	setcolor(RED);
	rectangle(x1-WIDTH,y1-WIDTH,x2,y2);
}

void buttondown(int x1,int y1,int x2,int y2)//按钮按下状态
{
	int WIDTH=5;
	int i;
	setfillstyle(1,WHITE);
	bar(x1,y1,x2,y2);
	for(i=0;i<WIDTH;i++)
	{
		setcolor(YELLOW);
		moveto(x1-WIDTH+i,y1-WIDTH+i);
		lineto(x2,y1-WIDTH+i);
		setcolor(LIGHTGRAY);
		moveto(x1-WIDTH+i,y1-WIDTH+i);
		lineto(x1-WIDTH+i,y2);
	}
}

void station(int x,int y)//普通站点
{
	setcolor(YELLOW);
	circle(x,y,2);
	circle(x,y,3);
	setcolor(LIGHTBLUE);
	circle(x,y,4);
	circle(x,y,5);
}

void stationb(int x,int y)//大站点
{
	setcolor(GREEN);
	circle(x,y,4);
	circle(x,y,3);
	setcolor(LIGHTGRAY);
	circle(x,y,5);
	circle(x,y,6);
}

void stationdown(int x,int y)//站点被选中状态
{
	setcolor(RED);
	circle(x,y,2);
	circle(x,y,3);
	setcolor(WHITE);
	circle(x,y,4);
	circle(x,y,5);
}

void stationdownb(int x,int y)//大站被选状态
{
	setcolor(RED);
	circle(x,y,3);
	circle(x,y,4);
	circle(x,y,5);
	setcolor(GREEN);
	circle(x,y,6);
	circle(x,y,7);
	setcolor(WHITE);
	circle(x,y,8);
}

void body1(int i,int j)//画人
{
	circle(i,j,20);
	moveto(i-10,j+16);
	lineto(i-10,j+24);
	moveto(i+10,j+16);
	lineto(i+10,j+24);
	lineto(i-10,j+24);
	lineto(i-23,j+25);
	lineto(i-73,j+85);
	lineto(i-60,j+92);
	lineto(i-23,j+50);
	lineto(i-23,j+110);
	lineto(i+23,j+110);
	lineto(i+23,j+50);
	lineto(i+26,j+50);
	lineto(i+26,j+100);
	lineto(i+39,j+100);
	lineto(i+39,j+34);
	lineto(i+20,j+24);
	lineto(i+10,j+24);
	moveto(i-23,j+110);
	lineto(i-45,j+150);
	lineto(i-23,j+180);
	lineto(i-10,j+170);
	lineto(i-25,j+150);
	lineto(i,j+125);
	lineto(i+5,j+190);
	lineto(i+23,j+190);
	lineto(i+23,j+110);
	moveto(i-18,j-6);
	lineto(i+18,j-6);
	setfillstyle(1,RED);
	floodfill(i,j+100,WHITE);
	setfillstyle(1,CYAN);
	floodfill(i,j+115,WHITE);
	setfillstyle(1,WHITE);
	floodfill(i,j,WHITE);
	floodfill(i,j+21,WHITE);
	setfillstyle(1,BROWN);
	floodfill(i,j-7,WHITE);
}

void body2(int i,int j)//另一朝向的人
{
	circle(i,j,20);
	moveto(i+10,j+16);
	lineto(i+10,j+24);
	moveto(i-10,j+16);
	lineto(i-10,j+24);
	lineto(i+10,j+24);
	lineto(i+23,j+25);
	lineto(i+73,j+85);
	lineto(i+60,j+92);
	lineto(i+23,j+50);
	lineto(i+23,j+110);
	lineto(i-23,j+110);
	lineto(i-23,j+50);
	lineto(i-26,j+50);
	lineto(i-26,j+100);
	lineto(i-39,j+100);
	lineto(i-39,j+34);
	lineto(i-20,j+24);
	lineto(i-10,j+24);
	moveto(i+23,j+110);
	lineto(i+45,j+150);
	lineto(i+23,j+180);
	lineto(i+10,j+170);
	lineto(i+25,j+150);
	lineto(i,j+125);
	lineto(i-5,j+190);
	lineto(i-23,j+190);
	lineto(i-23,j+110);
	moveto(i+18,j-6);
	lineto(i-18,j-6);
	setfillstyle(1,RED);
	floodfill(i,j+100,WHITE);
	setfillstyle(1,CYAN);
	floodfill(i,j+115,WHITE);
	setfillstyle(1,WHITE);
	floodfill(i,j,WHITE);
	floodfill(i,j+21,WHITE);
	setfillstyle(1,BROWN);
	floodfill(i,j-7,WHITE);
}

float calculate(int x,int z)//计算票价
{
	int n=z+1;
	int k;
	float m=0;
 
	if(1<=n&&n<5)
	{
		if(x<=5)
		{
			k=abs(n-x);
			m=k*0.5;
		}
		else if(5<x&&x<10)
		{
			m=(5-n)*0.5+(x-5)*0.5;
		}
		else if(10<=x&&x<14)
		{
			m=(5-n)*0.5+(14-x)*0.5;
		}
		else if(14<=x&&x<19)
		{
			m=(5-n)*0.5+(x-14)*0.5;
		}
	}  
	if(6<=n&&n<10)
	{
		if(1<=x&&x<=5)
		{
			m=(5-x)*0.5+(n-5)*0.5;
		}
		else if(5<x&&x<10)
		{
			k=abs(x-n);
			m=k*0.5;
		}
		else if(10<=x&&x<14)
		{
			m=(n-5)*0.5+(14-x)*0.5;
		}
		else if(14<=x&&x<19)
		{
			m=(n-5)*0.5+(x-14)*0.5;
		}
	}  
	if(10<=n&&n<14)
	{
		if(1<=x&&x<=5)
		{
			m=(14-n)*0.5+(5-x)*0.5;
		}
		else if(5<x&&x<10)
		{
			m=(14-n)*0.5+(x-5)*0.5;
		}
		else if(10<=x&&x<14)
		{
			k=abs(x-n);
			m=k*0.5;
		}
		else if(14<=x&&x<19)
		{
			m=(14-n)*0.5+(x-14)*0.5;
		}
	}  
	if(15<=n&&n<19)
	{
		if(1<=x&&x<=5)
		{
			m=(5-x)*0.5+(n-14)*0.5;
		}
		else if(5<x&&x<10)
		{
			m=(n-14)*0.5+(x-5)*0.5;
		}
		else if(10<=x&&x<14)
		{
			m=(n-14)*0.5+(14-x)*0.5;
		}
		else if(14<=x&&x<19)
		{
			k=abs(x-n);
			m=k*0.5;
		}
	}  
	if(n==5||n==14)
	{
		if(1<=x&&x<=5)
		{
			m=(5-x)*0.5;
		}
		else if(5<x&&x<10)
		{
			m=(x-5)*0.5;
		}
		else if(10<=x&&x<14)
		{
			m=(14-x)*0.5;
		}
		else if(14<=x&&x<19)
		{
			m=(x-14)*0.5;
		}
	}   
	if(m<1)//票价若小于1元，责为一元
	{
		m=1;
	}
	return m;
}

void chenche()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"d:\\borlandC\\bgi");
	
	drawgetup();
	
    int m=600;
	int n=290;
	int k=0;
	int t=0;
	while(1)//判断方向键
	{
		k=bioskey(0);
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
		else if((k==0x4b00)&&(m>0))
		{
			setfillstyle(1,LIGHTGRAY);
			bar(m-75,n-21,m+75,n+200);
			body1(m-5,n);
			t=0;
			m=m-5;
		}
		else  if((k==0x4d00)&&(m<600))
		{
			setfillstyle(1,LIGHTGRAY);
			bar(m-75,n-21,m+75,n+200);
			body2(m+5,n);
			t=1;
			m=m+5;
		}
		else if((k==0x4800)&&(n>220))
		{
			if(t==0)
			{
				setfillstyle(1,LIGHTGRAY);
				bar(m-75,n-21,m+75,n+200);
				body1(m,n-5);
				n=n-5;
			}
			if(t==1)
			{
				setfillstyle(1,LIGHTGRAY);
				bar(m-75,n-21,m+75,n+200);
				body2(m,n-5);
				n=n-5;
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
			}
			if(t==1)
			{
				setfillstyle(1,LIGHTGRAY);
				bar(m-75,n-21,m+75,n+200);
				body2(m,n+5);
				n=n+5;
			}
		}
		else
		{
			k=0;
		}
	}
}

void drawgetup()//画出乘车基本界面
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

struct route
{
	int x;
	int y;
	char name[20];
	char code[20];
};

int goupiaojiemian(int z,float *money1)
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"d:\\borlandC\\bgi");

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
	initmouse(1,635,1,475);
	cursor(mouse_x,mouse_y);
	
	drawjiemian(z);
	
	for(;;)
	{
		newmouse(&mouse_x,&mouse_y,&mouseclick);//鼠标
		buttonclick(mouse_x,mouse_y,mouseclick);//实现惦记
 		stationchoose(mouse_x,mouse_y,mouseclick,&flag2,&money,z,&flag,&forp);//实现选站
		routechoose(&flag2,mouse_x,mouse_y,mouseclick);//实现选择路线
		p=zh+forp;
		//实现改站
		if(540<mouse_x&&mouse_x<630&&90<mouse_y&&mouse_y<120&&mouseclick)
		{
			buttondown(558,90,630,120);
			puts12(570,93,"更改",RED,2,2);
			delay(100);
			closegraph();
			return 3;
		}
        //退出并保存
		if(310<mouse_x&&mouse_x<400&&10<mouse_y&&mouse_y<50&&mouseclick)
		{
			printf("%d",forp);
			writedata(p->name);
			writedata(state1);			
			writedata(" ");	
			delay(100);
			return 2;
		}
		//实现传递
		if(210<mouse_x&&mouse_x<300&&10<mouse_y&&mouse_y<50&&mouseclick&&flag==1)
		{
			*money1=money;
			writedata(p->name);
			writedata(state2);
			writedata(" ");
			delay(100);
			closegraph();
			return 4;
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
	button(558,90,630,120);
	puts12(12,13,"一号线",RED,2,2);
	puts12(112,13,"二号线",RED,2,2);
	puts12(212,13,"确定",RED,2,2);
	puts12(312,13,"退出",RED,2,2);
	puts12(570,93,"更改",RED,2,2);
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
	moveto(420,130);
	lineto(640,130);
	//画出信息
	p=zh+z;
	puts12(455,28,"当前车站",RED,3,3);
	puts12(430,150,"从",RED,2,2);
	puts12(430,190,"到",RED,2,2);
	puts12(430,90,p->name,YELLOW,2,2);
	puts12(460,150,p->name,YELLOW,2,2);
	puts12(430,230,"的票价为",RED,2,2);
	puts12(580,230,"元",RED,2,2);
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
	chatu(423,269,0.9,"D:\\BORLANDC\\BIN\\KESHE2\\PICT\\LZ16.DAT");
}

void buttonclick(int mouse_x,int mouse_y,int mouseclick)
{		
	//实现点击按钮效果
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
		*flag2=1;
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
		setlinestyle(0,0,3);
		setcolor(RED);
		moveto(80,100);
		for(p=zh;p<zh+9;p++)
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
	}  
	if(110<mouse_x&&mouse_x<200&&10<mouse_y&&mouse_y<50&&mouseclick)
	{
		*flag2=1;
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
		
		setlinestyle(0,0,3);
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
	}    
}

void stationchoose(int mouse_x,int mouse_y,int mouseclick,int *flag2,float *money,int z,int *flag,int *forp)
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
	
	int num=0;

	char *mon;
	int dec,sign;
	float moneyy;//用与接收*MONEY的植显示在屏幕上
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
		bar(460,190,640,220);
		bar(525,230,560,260);
		*money=calculate(num,z);//计算票价
		moneyy=*money;
		mon=fcvt(moneyy,1,&dec,&sign);//显示票价
		settextstyle(1,0,3);
		outtextxy(535,230,mon);
		outtextxy(546,234,".");
		passroute(num,z);//画出路线
		p=zh+num-1;
		puts12(460,190,p->name,YELLOW,2,2);
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

int jinzhan()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"d:\\borlandC\\bgi");

	int i;

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

	//列车进站动画
	for(i=0;i<400;i=i+10)
	{
		setcolor(BLUE);
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
		puts12(i+90,415,"和谐号",YELLOW,2,2);

		setfillstyle(1,YELLOW);
		delay(400);
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
 
	getch();
	closegraph();
	return 1;
}

void showtime()
{
	struct tm *ptr;
	time_t it;
	int *a,b;
	char *tim;
	setcolor(BLUE);

	//显示时间
	it=time(NULL);
	ptr=localtime(&it);
	setcolor(BLUE);
	tim=fcvt(ptr->tm_min,0,0,0);
	outtextxy(130,460,tim);
	tim=fcvt(ptr->tm_hour,0,0,0);
	outtextxy(110,460,tim);
	outtextxy(123,460,":");
	tim=fcvt(ptr->tm_mon+1,0,0,0);
	outtextxy(55,460,tim);
	tim=fcvt(ptr->tm_year+1900,0,0,0);
	outtextxy(17,460,tim);
	outtextxy(49,460,"-");
	tim=fcvt(ptr->tm_mday,0,0,0);
	outtextxy(80,460,tim);
	outtextxy(70,460,"-");
	tim=fcvt(ptr->tm_wday,0,0,0);

	switch(ptr->tm_wday)
	{
		case 1:
			outtextxy(180,460,"Monday");
			break;
		case 2:
			outtextxy(180,460,"Tuesday");
			break;
		case 3:
			outtextxy(180,460,"Wednesday");
			break;
		case 4:
			outtextxy(180,460,"Thursday");
			break;
		case 5:
			outtextxy(180,460,"Friday");
			break;
		case 6:
			outtextxy(180,460,"Saturday");
			break;
		case 7:
			outtextxy(180,460,"Sunday");
			break;
	}	 
	outtextxy(470,460,"All Rights Reserved");	
}

struct route
{
	int x;
	int y;
	char name[20];
	char code[20];
};

int changestart()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"d:\\borlandC\\bgi");
 
    cleardevice();
	drawstart();//画出界面

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
	int num=0,oldnum=0;	
	
	initmouse(1,635,1,475);
	cursor(mouse_x,mouse_y);
	int z;

	for(;;)
	{
		newmouse(&mouse_x,&mouse_y,&mouseclick);
		//实现鼠标选站
		if(mouseclick)
		{
			num=xuanzhan(mouse_x,mouse_y,mouseclick);
		}
		//实现键盘选站
		int ch;
		if(kbhit())
		{
			ch=bioskey(0);
			num=kbxuanzhan(ch);	
		}	
		//选站之后的刷新与返回数值
		if(num!=oldnum&&num<20)
		{
			setfillstyle(1,LIGHTBLUE);
			bar(460,190,640,220);//覆盖原有
			bar(525,230,560,260);
			oldnum=num;
			p=zh+num-1;
			puts12(460,190,p->name,YELLOW,2,2);
			mouseclick=0;
			z=num-1;         //返回Z的值                        
		}		
		
	    //确定
		if(460<mouse_x&&mouse_x<600&&30<mouse_y&&mouse_y<100&&mouseclick)
		{
			buttondown(460,30,600,100);
			puts12(470,40,"确定",BLACK,3,3);
			delay(100);
			return z;
			getch();
		}
	}
}
void drawstart()
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
	int mouse_x=0,mouse_y=0, mouseclick=0; 
	int num=0,oldnum=0;			  

	setbkcolor(LIGHTBLUE);
	puts12(37,13,"请通过鼠标选择出发站",YELLOW,3,3);
	puts12(450,150,"当前出发站",RED,2,2);
	button(460,30,600,100);
	puts12(470,40,"确定",BLACK,3,3);

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
	setlinestyle(0,0,3);
	setcolor(MAGENTA);
	moveto(420,0);
	lineto(420,500);
	moveto(0,70);
	lineto(420,70);
	moveto(420,130);
	lineto(640,130);
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
}

void writedata(char *ch)
{
	FILE *fp;
	int i=0;
	fp=fopen("d:\\borlandc\\bin\\keshe2\\shuju.txt","a");
	if(!fp)
	{
		printf("cannot open the file!");
		getch();
		exit(1);
	}
	while(ch[i]!='\0')
	{
		fputc(ch[i],fp);
		i++;
	}
	fputc('\n',fp);
	fclose(fp);
}

void welcome()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"d:\\borlandC\\bgi");

	int i,j;
	char *timm;

	showtime();

	setcolor(5);
	settextjustify(CENTER_TEXT,1);
	settextstyle(TRIPLEX_FONT,0,7);
	outtextxy(320,100,"Welcome To");

	for(j=0;j<10;j++)
	{
		if(j%2==0)
		{
			setcolor(3);
			outtextxy(320,250,"Subway System !");
		delay(500);
		}
		else
		{
			setcolor(5);
			outtextxy(320,250,"Subway System !");
			delay(500);
		}
	}

	puts12(102,313,"作者",RED,2,2);
	delay(700);
	puts12(170,313,"陈旭东",YELLOW,2,2);
	delay(700);
	puts12(170,343,"肖标",YELLOW,2,2);
	delay(700);
	closegraph();
}

void chuzhan()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"d:\\borlandC\\bgi");

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

		delay(400);
	}
	setcolor(YELLOW);
	bar(0,180,640,260);
	
	puts12(50,100,"列车已离站，谢谢乘坐，祝您愉快！",RED,3,3);
	getch();
	closegraph();
}

以下函数为借用他人成果，不计入行数

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

/* 显示12*12点阵汉字函数，使用HZK12文件，x,y为显示坐标，s为显示字符串，colour为颜色 */
void hanzi12(int x,int y,char *s,int colour)
{
 FILE *fp;
 char buffer[24];
 register i,j,k;
 unsigned char qh,wh;
 unsigned long location;
 if((fp=fopen("hzk12","rb"))==NULL)
 {
 printf("Can't open hzk12!");
 getch();
 }
 while(*s)
 {
 qh=*(s)-0xa0;
 wh=*(s+1)-0xa0;
 location=(94*(qh-1)+(wh-1))*24L;
 fseek(fp,location,SEEK_SET);
 fread(buffer,24,1,fp);
 for(i=0;i<12;i++)
 for(j=0;j<2;j++)
 for(k=0;k<8;k++)
 if((buffer[i*2+j]>>(7-k))&0x1)
 putpixel(x+k,y+i,colour);
 s+=2;
 x+=12;
 }
 fclose(fp);
}

/* 中英文混合输出函数，使用HZK16,ASC16文件，x,y为显示坐标，s为显示字符串，colour为颜色 */
void puts16(int x,int y,char *s,int colour,int ha,int lie)
{
 register int i,j,k,n,m;
 FILE *fpa,*fph;
 char buffera[16],bufferh[32];
 unsigned char qh,wh;
 unsigned long location;

 fpa=fopen("asc16","rb");
 fph=fopen("hzk16","rb");
 while(*s)
 {
 if(*s>0)
 {
 fseek(fpa,(*s)*16,0);
 fread(buffera,1,16,fpa);
 for(n=0;n<lie;n++)
 for(i=0;i<16;i++)
 for(j=0;j<8;j++)
 for(m=0;m<ha;m++)
 {
 if(((buffera[i]>>(7-j))&0x1)!=NULL)
 putpixel(j*ha+x+m,i*lie+y+n,colour);
 }
 s++;
 x+=8*ha;
 }
 else
 {
 qh=*s-0xa0;
 wh=*(s+1)-0xa0;
 location=(94*(qh-1)+(wh-1))*32L;
 fseek(fph,location,SEEK_SET);
 fread(bufferh,1,32,fph);
 for(i=0;i<16;i++)
 for(n=0;n<lie;n++)
 for(j=0;j<2;j++)
 for(k=0;k<8;k++)
 for(m=0;m<ha;m++)
 if(((bufferh[i*2+j]>>(7-k))&0x1)!=NULL)
 putpixel(x+8*j*ha+k*ha+m,y+i*lie+n,colour);
 s+=2;
 x+=16*ha;
 }
 }
 fclose(fpa);
 fclose(fph);
}
void puts12(int x,int y,char *s,int colour,int ha,int lie)
{
 register int i,j,k,n,m;
 FILE *fpa,*fph;
 char buffera[12],bufferh[24];
 unsigned char qh,wh;
 unsigned long location;

 fpa=fopen("asc12","rb");
 fph=fopen("hzk12","rb");
 while(*s)
 {
 if(*s>0)
 {

 fseek(fpa,(*s)*12,0);
 fread(buffera,1,12,fpa);
 //for(n=0;n<lie;n++)
 for(i=0;i<12;i++)
 for(j=0;j<8;j++)
 //for(m=0;m<ha;m++)
 {
 if(((buffera[i]>>(7-j))&0x1)!=NULL)
 putpixel(j+x,i+y,colour);
 }
 s++;
 x+=6*ha;
 }
 else
 {
 qh=*s-0xa0;
 wh=*(s+1)-0xa0;
 location=(94*(qh-1)+(wh-1))*24L;
 fseek(fph,location,SEEK_SET);
 fread(bufferh,1,24,fph);
 for(i=0;i<12;i++)
 for(n=0;n<lie;n++)
 for(j=0;j<2;j++)
 for(k=0;k<8;k++)
 for(m=0;m<ha;m++)
 if(((bufferh[i*2+j]>>(7-k))&0x1)!=NULL)
 putpixel(x+8*j*ha+k*ha+m,y+i*lie+n,colour);
 s+=2;
 x+=12*ha;
 }
 }
 fclose(fpa);
 fclose(fph);
}

void chatu(int x,int y,float k,char *filename)   //k为放大倍数（整数）
{
	FILE *fp;
	int color;
	int i,j;
	int width,height;

	if((fp=fopen(filename,"rb"))!=NULL)
	{
		fread(&width,2,1,fp);
		fread(&height,2,1,fp);

		for(i=0;i<height;i++)
		{
			for(j=0;j<width;j++)
			{
				fread(&color,1,1,fp);
				if(color%16!=0)
				{
					if(k!=1)
					{
						setfillstyle(1,color);
						bar(x+j*k,y+i*k,x+j*k+k,y+i*k+k);
					}
					else if(k==1)
					{
						putpixel(x+j,y+i,color);
					}
				}
			}
		}
		fclose(fp);
	}
	else
	{
		printf("%s",filename);
		printf("error in loadimage file open fail");
		getch();
		exit(1);
	}
}

void load_pic(char *fname)
{
	FILE *fp;
	int k=1;
	register int i;
	register long j;
	char far *ptr;
	fp=fopen(fname,"rb");
	for(i=0;i<4;i++)
	{
		outportb(0x3c4,2);
		outportb(0x3c5,k);
		ptr=(char far *)0xa0000000l;
		for(j=0;j<38400l;j++)
		{
			*ptr=getc(fp);
			ptr++;
		}
	k*=2;
	}
	fclose(fp);
	//outportb(0x3c5,0xf);
}

#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<alloc.h>

void puts12(int x,int y,char *s,int colour,int ha,int lie);
void showtime();
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<bios.h>
#include"TOU.H"
#include<bios.h>

void body1(int i,int j);
void body2(int i,int j);
void puts12(int x,int y,char *s,int color,int ha,int lie);
void showtime();
void drawgetup();
#include<stdio.h>
#include<math.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<bios.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

void button(int x1,int y1,int x2,int y2);
void buttondown(int x1,int y1,int x2,int y2);
void station(int x,int y);
void stationdown(int x,int y);
void stationb(int x,int y);
void stationdownb(int x,int y);
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<bios.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

void station(int x,int y);
void stationdown(int x,int y);
void stationb(int x,int y);
void stationdownb(int x,int y);
void cursor(int x,int y);
void newmouse(int *x,int *y,int *mbutt);
int readmouse(int *mx,int *my,int *mbutt);
int initmouse(int xmi,int xma,int ymi,int yma);
void puts16(int x,int y,char *s,int colour,int ha,int lie);
void puts12(int x,int y,char *s,int colour,int ha,int lie);
void button(int x1,int y1,int x2,int y2);
void buttondown(int x1,int y1,int x2,int y2);
char showtime();
void drawstart();
int xuanzhan(int mouse_x,int mouse_y,int mouseclick);
int kbxuanzhan(int ch);
#include<time.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<alloc.h>

void puts12(int x,int y,char *s,int colour,int ha,int lie);
void showtime();
