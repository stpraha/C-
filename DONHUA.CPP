
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




void toubidonhua1()
{
	huaqianbi1();
	int maxy=240;
	int size1,size2,size3;
	void *buffer1,*buffer2,*buffer3;

	 /*得到一元硬币图像*/
	size1=imagesize(308,322,342,388);
	buffer1=malloc(size1);
	getimage(308,322,342,388,buffer1);
	/*保存投币机图像*/
	size2=imagesize(68,110,240,310);
	buffer2=malloc(size2);
	getimage(68,110,240,310,buffer2);
	size3=imagesize(108,100,160,190);
	buffer3=malloc(size3);
	getimage(108,100,160,190,buffer3);
	while(maxy>100)
	{
		putimage(112,maxy,buffer1,COPY_PUT);
		putimage(108,100,buffer3,COPY_PUT);
		delay(100);
		putimage(68,110,buffer2,COPY_PUT);
		delay(100);
		maxy-=10;

	}
	putimage(68,110,buffer2,COPY_PUT);
	free(buffer1);
	free(buffer2);
	free(buffer3);
}
void toubidonhua5()
{
	huaqianbi5();
	int maxy=240;
	int size1;
	int size2;
	int size3;
	void *buffer1;
	void *buffer2;
	void *buffer3;

	 /*得到五元钱币图像*/
	size1=imagesize(206,322,240,388);
	buffer1=malloc(size1);
	getimage(206,322,240,388,buffer1);
	/*保存投币机图像*/
	size2=imagesize(68,110,240,310);
	buffer2=malloc(size2);
	getimage(68,110,240,310,buffer2);
	size3=imagesize(108,100,160,190);
	buffer3=malloc(size3);
	getimage(108,100,160,190,buffer3);
	while(maxy>100)
	{
		putimage(112,maxy,buffer1,COPY_PUT);
		putimage(108,100,buffer3,COPY_PUT);
		delay(100);
		putimage(68,110,buffer2,COPY_PUT);
		delay(100);
		maxy-=10;

	}
	putimage(68,110,buffer2,COPY_PUT);
	free(buffer1);
	free(buffer2);
	free(buffer3);

}
void toubidonhua10()
{
	huaqianbi10();
	int maxy=240;
	int size1;
	int size2;
	int size3;
	void *buffer1 ;
	void *buffer2;
	void *buffer3;

	 /*得到十元钱币图像*/
	size1=imagesize(113,322,147,388);
	buffer1=malloc(size1);
	getimage(113,322,147,388,buffer1);
	/*保存投币机图像*/
	size2=imagesize(68,110,240,310);
	buffer2=malloc(size2);
	getimage(68,110,240,310,buffer2);
	size3=imagesize(108,100,160,190);
	buffer3=malloc(size3);
	getimage(108,100,160,190,buffer3);
	while(maxy>100)
	{
		putimage(112,maxy,buffer1,COPY_PUT);
		putimage(108,100,buffer3,COPY_PUT);
		delay(100);

		putimage(68,110,buffer2,COPY_PUT);
		delay(100);
		maxy-=10;

	}
	putimage(68,110,buffer2,COPY_PUT);
	free(buffer1);
	free(buffer2)  ;
	free(buffer3);
}
void zhaolindonhua1()
{
	huaqianbi1();
   int miny=141;
   int size1;
   int size2;
   int size3;
   void *buffer1;
   void *buffer2;
   void *buffer3;
   size1=imagesize(308,322,342,388);
   buffer1=malloc(size1);
   getimage(308,322,342,388,buffer1);
   size2=imagesize(350,110,500,350);
   buffer2=malloc(size2);
   getimage(350,110,500,350,buffer2);
   size3=imagesize(398,141,468,181);
   buffer3=malloc(size3);
   getimage(398,141,468,181,buffer3);
   while(miny<281)
   {
		putimage(410,miny,buffer1,COPY_PUT);
		putimage(398,141,buffer3,COPY_PUT);
		delay(100);
		putimage(350,110,buffer2,COPY_PUT);
		delay(100);
		miny+=10 ;

   }
   putimage(350,110,buffer2,COPY_PUT);
   free(buffer1);
   free(buffer2);
   free(buffer3);

}

void zhaolindonhua5()
{
	huaqianbi5();
   int miny=141;
   int size1;
   int size2;
   int size3;
   void *buffer1;
   void *buffer2;
   void *buffer3;
   size1=imagesize(206,322,240,388);
   buffer1=malloc(size1);
   getimage(206,322,240,388,buffer1);
   size2=imagesize(350,110,500,350);
   buffer2=malloc(size2);
   getimage(350,110,500,350,buffer2);
   size3=imagesize(398,141,468,181);
   buffer3=malloc(size3);
   getimage(398,141,468,181,buffer3);
   while(miny<281)
   {
		putimage(410,miny,buffer1,COPY_PUT);
		putimage(398,141,buffer3,COPY_PUT);
		delay(100);
		putimage(350,110,buffer2,COPY_PUT);
		delay(100);
		miny+=10;

   }
   putimage(350,110,buffer2,COPY_PUT);
   free(buffer1);
   free(buffer2);
   free(buffer3);

}
