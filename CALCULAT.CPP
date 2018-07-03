#include"calculat.h"
float calculate(int x,int z)//计算票价
{
	int n=z+1;
	int k;
	float m=0;
 
	if(1<=n&&n<5)
	{
		if(x<=5)
		{
			k=abs(n-x);
			m=k*0.5;
		}
		else if(5<x&&x<10)
		{
			m=(5-n)*0.5+(x-5)*0.5;
		}
		else if(10<=x&&x<14)
		{
			m=(5-n)*0.5+(14-x)*0.5;
		}
		else if(14<=x&&x<19)
		{
			m=(5-n)*0.5+(x-14)*0.5;
		}
	}  
	if(6<=n&&n<10)
	{
		if(1<=x&&x<=5)
		{
			m=(5-x)*0.5+(n-5)*0.5;
		}
		else if(5<x&&x<10)
		{
			k=abs(x-n);
			m=k*0.5;
		}
		else if(10<=x&&x<14)
		{
			m=(n-5)*0.5+(14-x)*0.5;
		}
		else if(14<=x&&x<19)
		{
			m=(n-5)*0.5+(x-14)*0.5;
		}
	}  
	if(10<=n&&n<14)
	{
		if(1<=x&&x<=5)
		{
			m=(14-n)*0.5+(5-x)*0.5;
		}
		else if(5<x&&x<10)
		{
			m=(14-n)*0.5+(x-5)*0.5;
		}
		else if(10<=x&&x<14)
		{
			k=abs(x-n);
			m=k*0.5;
		}
		else if(14<=x&&x<19)
		{
			m=(14-n)*0.5+(x-14)*0.5;
		}
	}  
	if(15<=n&&n<19)
	{
		if(1<=x&&x<=5)
		{
			m=(5-x)*0.5+(n-14)*0.5;
		}
		else if(5<x&&x<10)
		{
			m=(n-14)*0.5+(x-5)*0.5;
		}
		else if(10<=x&&x<14)
		{
			m=(n-14)*0.5+(14-x)*0.5;
		}
		else if(14<=x&&x<19)
		{
			k=abs(x-n);
			m=k*0.5;
		}
	}  
	if(n==5||n==14)
	{
		if(1<=x&&x<=5)
		{
			m=(5-x)*0.5;
		}
		else if(5<x&&x<10)
		{
			m=(x-5)*0.5;
		}
		else if(10<=x&&x<14)
		{
			m=(14-x)*0.5;
		}
		else if(14<=x&&x<19)
		{
			m=(x-14)*0.5;
		}
	}   
	if(m<1)//票价若小于1元，责为一元
	{
		m=1;
	}
	return m;
}