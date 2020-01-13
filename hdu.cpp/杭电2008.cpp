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
	int a,b,c,i,size;
	double number;
	while(scanf("%d",&size)&&size)
	{
		a=0;
		b=0;
		c=0;
		for(i=0;i<size;i++)
		{
			scanf("%lf",&number);
			if(number<0)
				a++;
			else if(number==0)
				b++;
			else 
				c++;
		}
		printf("%d %d %d\n",a,b,c);
	}
	return 0;
}
