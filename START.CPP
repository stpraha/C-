#include"start.h"

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
	initgraph(&gdriver,&gmode,"D:\\borlandC\\bgi");
 
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
       //	int mouse_x=0,mouse_y=0, mouseclick=0;
       //	int num=0,oldnum=0;

	setbkcolor(LIGHTBLUE);
	puts12(37,13,"请通过键鼠选择出发站",YELLOW,3,3);
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
