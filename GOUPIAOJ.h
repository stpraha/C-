#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<bios.h>
#include<time.h>
#include<string.h>
void button(int x1,int y1,int x2,int y2);
void buttondown(int x1,int y1,int x2,int y2);
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
float calculate(int x,int z);
//void ceshi(int i);
int xuanzhan(int mouse_x,int mouse_y,int mouseclick);
int kbxuanzhan(int ch);
void writedata(char *ch);
int changestart();
void chatu(int x,int y,float k,char *filename);
void showtime();
void buttonclick(int mouse_x,int mouse_y,int mouseclick);
void drawjiemian(int z);
void routechoose(int *flag2,int mouse_x,int mouse_y,int mouseclick);
void stationchoose(int mouse_x,int mouse_y,int mouseclick,int *flag2,float *money,int z,int *flag,int *forp,int ticnum);
void passroute(int num,int z);
void ticketnum(int mouse_x,int mouse_y,int mouseclick,int *ticnum,float *money);