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
	long long int a[100]={0,1,2,3};
	int i,j,size;
	for(i=4;i<=50;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	scanf("%d",&size);
	while(size--)
	{
		scanf("%d %d",&i,&j);
		printf("%lld\n",a[j-i]);
	}
	return 0;
}
