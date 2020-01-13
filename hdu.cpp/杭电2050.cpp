//f(n)=2n2 -n + 1»òf(n)=f(n-1)+4*£¨n-1£©+1
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
	long long int a[10001]={1,2,7}; 
    int i,t;
    for(i=3;i<=10000;i++)
	{
			a[i]=a[i-1]+4*(i-1)+1;	
	}
	scanf("%d",&t);
	while(t--)
	{	
		scanf("%d",&i);	
		printf("%lld\n",a[i]);
	}
	return 0;
}
