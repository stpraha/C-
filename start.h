#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<bios.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

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
void button(int x1,int y1,int x2,int y2);
void buttondown(int x1,int y1,int x2,int y2);
char showtime();
void drawstart();
int xuanzhan(int mouse_x,int mouse_y,int mouseclick);
int kbxuanzhan(int ch);
