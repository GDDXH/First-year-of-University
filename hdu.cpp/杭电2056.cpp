#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
void change(double &a,double &b)
{
	double t;
	t=a;
	a=b;
	b=t;
}
int main()
{
	double x1,x2,x3,x4,y1,y2,y3,y4;
	double r1,r2,r3,r4;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)
	{
		if(x1<x2) change(x1,x2);
		if(y1<y2) change(y1,y2);
		if(x3<x4) change(x3,x4);
		if(y3<y4) change(y3,y4);
		if(x1<x4||y1<y4||x3<x2||y3<y2)
			cout<<"0.00"<<endl;
		else
			{
				if(x1>=x3)
					r1=x3;		
				else
					r1=x1;
				if(y1>=y3)
					r2=y3;		
				else
					r2=y1;
				if(x2>=x4)
					r3=x2;
				else
					r3=x4;
				if(y2>=y4)
					r4=y2;
				else
					r4=y4;
				cout<<setprecision(2)<<fixed<<(r1-r3)*(r2-r4)<<endl;
			}
	 } 
	 return 0;
}
