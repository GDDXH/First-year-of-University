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
	long long int a[100]={0,3,8,22};
	int i;
	for(i=4;i<40;i++)
	{
		a[i]=2*a[i-1]+2*a[i-2];
	}
	while(scanf("%d",&i)!=EOF)
	{
		printf("%lld\n",a[i]);
	}
	return 0;
	
}
