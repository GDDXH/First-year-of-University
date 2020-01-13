#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	double m,n;
	while(~scanf("%lf%lf",&m,&n))
	{
		double result=0;
		for(int i=0;i<n;i++)
		{
			result+=m;
			m=sqrt(m);
		}
		printf("%.2lf\n",result);
	}	 
	return 0;
}
