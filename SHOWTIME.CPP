#include"showtime.h"

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