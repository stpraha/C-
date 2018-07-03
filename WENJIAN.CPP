#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void writedata(char *ch)
{
	FILE *fp;
	int i=0;
	fp=fopen("D:\\borlandc\\lala1l\\shuju.txt","a");
	if(!fp)
	{
		printf("cannot open the file!");
		getch();
		exit(1);
	}
	while(ch[i]!='\0')
	{
		fputc(ch[i],fp);
		i++;
	}
	fputc('\n',fp);
	fclose(fp);
}