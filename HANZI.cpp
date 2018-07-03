#include"HANZI.H"

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