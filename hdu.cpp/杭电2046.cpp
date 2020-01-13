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
	long long int a[100]={0,1,2,3};
	int i;
	for(i=4;i<=50;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	while(scanf("%d",&i)!=EOF)
	{
		printf("%lld\n",a[i]);
	}
	return 0;
	
}
