#include<iostream>
#include<cstdio>
#include<cstdlib> 
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	int a,b,c,k;
	while(scanf("%d %d %d",&a,&b,&c))
	{
		if(a==0&&b==0)
		{
			break;
		}
		k=pow(10,c);
		if(a%k==b%k)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",a+b);
		}
	 } 
	 return 0;
}
