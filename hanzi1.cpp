#include<stdio.h>
#include<graphics.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<io.h>
#include<bios.h>
#include"hanzi1.h"

void hanzi(char *str, int x,int y,int d,int ROW,int COL,int color)
{
	FILE *fp;
	char buffer[32];   //buffer用来存储一个汉字
	int m,n,i,j,k;
	unsigned char qh,wh;
	unsigned long offset;

	fp=fopen("hzk16","rb");
	while(*str)
	{

		qh=*str-0xa0;
		wh=*(str+1)-0xa0;

		offset=(94*(qh-1)+(wh-1))*32L;  //计算该汉字在字库中偏移量
		fseek(fp,offset,SEEK_SET);
		fread(buffer,32,1,fp); //取出汉字32字节的点阵字模存入buffer中（一个汉字）
		for (i=0;i<16;i++)  //将32位字节的点阵按位在屏幕上打印出来(1:打印,0:不打印),显示汉字
		for(n=0;n<ROW;n++)
		for(j=0;j<2;j++)
		for(k=0;k<8;k++)
		for(m=0;m<COL;m++)
		if(((buffer[i*2+j]>>(7-k))&0x1)!=NULL)
		putpixel(x+8*j*COL+k*COL+m,y+i*ROW+n,color);
		str+=2;
		x+=d;
	}
	fclose(fp);
}