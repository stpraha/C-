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
	drawstart();//��������

 	struct route zh[18]={{80,100,"����վ","a"},
				{150,120,"����վ","b"},
				{180,170,"��Էʳ��վ","c"},
				{180,250,"�Ƽ�¥վ","d"},
				{220,280,"��һ¥վ","e"},
				{300,290,"��ʮ��վ","f"},
				{330,320,"��С��վ","g"},
				{340,380,"�в�վ","h"},
				{310,440,"��һʳ��վ","i"},
				{120,450,"����վ","j"},
				{170,430,"��ʮ��վ","k"},
				{140,370,"�پ�԰վ","l"},
				{200,330,"��óվ","m"},
				{220,280,"��һ¥վ","n"},
				{260,220,"��С��վ","o"},
				{300,200,"������վ","p"},
				{350,170,"��԰ʳ��վ","q"},
				{360,120,"����վ","r"}};
				
				struct route *p;
				
	int mouse_x=0,mouse_y=0, mouseclick=0; 
	int num=0,oldnum=0;	
	
	initmouse(1,635,1,475);
	cursor(mouse_x,mouse_y);
	int z;

	for(;;)
	{
		newmouse(&mouse_x,&mouse_y,&mouseclick);
		//ʵ�����ѡվ
		if(mouseclick)
		{
			num=xuanzhan(mouse_x,mouse_y,mouseclick);
		}
		//ʵ�ּ���ѡվ
		int ch;
		if(kbhit())
		{
			ch=bioskey(0);
			num=kbxuanzhan(ch);	
		}	
		//ѡվ֮���ˢ���뷵����ֵ
		if(num!=oldnum&&num<20)
		{
			setfillstyle(1,LIGHTBLUE);
			bar(460,190,640,220);//����ԭ��
			bar(525,230,560,260);
			oldnum=num;
			p=zh+num-1;
			puts12(460,190,p->name,YELLOW,2,2);
			mouseclick=0;
			z=num-1;         //����Z��ֵ                        
		}		
		
	    //ȷ��
		if(460<mouse_x&&mouse_x<600&&30<mouse_y&&mouse_y<100&&mouseclick)
		{
			buttondown(460,30,600,100);
			puts12(470,40,"ȷ��",BLACK,3,3);
			delay(100);
			return z;
		}
	}
}
void drawstart()
{
	struct route zh[18]={{80,100,"����վ","a"},
				{150,120,"����վ","b"},
				{180,170,"��Էʳ��վ","c"},
				{180,250,"�Ƽ�¥վ","d"},
				{220,280,"��һ¥վ","e"},
				{300,290,"��ʮ��վ","f"},
				{330,320,"��С��վ","g"},
				{340,380,"�в�վ","h"},
				{310,440,"��һʳ��վ","i"},
				{120,450,"����վ","j"},
				{170,430,"��ʮ��վ","k"},
				{140,370,"�پ�԰վ","l"},
				{200,330,"��óվ","m"},
				{220,280,"��һ¥վ","n"},
				{260,220,"��С��վ","o"},
				{300,200,"������վ","p"},
				{350,170,"��԰ʳ��վ","q"},
				{360,120,"����վ","r"}};
	  			  
	int i=2,j=2;
       //	int mouse_x=0,mouse_y=0, mouseclick=0;
       //	int num=0,oldnum=0;

	setbkcolor(LIGHTBLUE);
	puts12(37,13,"��ͨ������ѡ�����վ",YELLOW,3,3);
	puts12(450,150,"��ǰ����վ",RED,2,2);
	button(460,30,600,100);
	puts12(470,40,"ȷ��",BLACK,3,3);

	showtime();
		
	struct route *p;
	//����վ��
	for(p=zh;p<zh+18;p++)
	{
		station(p->x,p->y);
	}
	//����һ����
	setlinestyle(0,0,i);
	setcolor(RED);
	moveto(80,100);
	for(p=zh;p<zh+9;p++)
	{
		lineto(p->x,p->y);
	}               
	//����������
	setlinestyle(0,0,j);
	setcolor(BROWN);
	moveto(120,450);
	for(p=zh+9;p<zh+18;p++)
	{
		lineto(p->x,p->y);
	}                  
	 //������վ
	stationb(220,280);
	setlinestyle(0,0,3);
	setcolor(MAGENTA);
	moveto(420,0);
	lineto(420,500);
	moveto(0,70);
	lineto(420,70);
	moveto(420,130);
	lineto(640,130);
	//д��վ���ͼ��̴����ķ���
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