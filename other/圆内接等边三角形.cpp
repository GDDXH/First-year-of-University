#include<iostream> 
#include<cmath>
#include<cstdio>  
#include<cstring> 
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double m,n;
		double x[2],y[2];
		scanf("%lf%lf",&m,&n);
		double r=m*m+n*n;
		x[0]=(-m+sqrt(3*n*n))/2;
		x[1]=(-m-sqrt(3*n*n))/2;
		y[0]=(-0.5*r-x[0]*m)/n;
		y[1]=(-0.5*r-x[1]*m)/n;
		if(y[0]<y[1])
		printf("%.3lf %.3lf %.3lf %.3lf\n",x[0],y[0],x[1],y[1]);
		else if(y[0]>y[1])
		printf("%.3lf %.3lf %.3lf %.3lf\n",x[1],y[1],x[0],y[0]);
		else if(x[0]<x[1])
		printf("%.3lf %.3lf %.3lf %.3lf\n",x[0],y[0],x[1],y[1]);
		else 
		printf("%.3lf %.3lf %.3lf %.3lf\n",x[1],y[1],x[0],y[0]);
	}
	return 0;
} 

