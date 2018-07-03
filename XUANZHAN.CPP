#include"xuanzhan.h"


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