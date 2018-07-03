#include<dos.h>
#include<graphics.h>
#include<bios.h>
#include<stdlib.h>
#include<stdio.h> 
#include<conio.h>
#include<string.h>
#include<dir.h>
#include<alloc.h>
#include<time.h>
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
		/*printf("%s",filename);
		printf("error in loadimage file open fail");
		getch();
		exit(1);*/
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