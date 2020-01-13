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
	int size;
	double a,b,c;
	bool flag;
	scanf("%d",&size);
	while(size--)
	{
		scanf("%lf %lf %lf",&a,&b,&c);
		if((a+b>c)&&(a+c>b)&&(b+c>a))
			flag=true;
		else
			flag=false;
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}	
	return 0;
}
