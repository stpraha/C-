#ifndef _MOUSE_H_
#define _MOUSE_H_




void cursor(int x, int y);
int initmouse(int xmi, int xma, int ymi, int yma);
int readmouse(int *mx, int *my,int *mbutt)  ;
void newmouse(int *mx, int*my, int*mbutt) ;
void hnewmouse(int *mx, int*my, int*mbutt) ;
#endif