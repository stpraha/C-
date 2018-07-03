#include"jinzhan.h"
void showtime();
void welcome()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"D:\\borlandC\\bgi");

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
      /*	puts12(300,313,"指导老师",RED,2,2);
	delay(700);
	puts12(410,313,"周纯杰",YELLOW,2,2);
	delay(700);
	puts12(410,343,"何顶新",YELLOW,2,2);
	delay(700);
	puts12(410,373,"彭刚",YELLOW,2,2);
	delay(700);
	puts12(410,403,"周凯波",YELLOW,2,2);
	delay(700); */
	delay(3000);
	closegraph();
}