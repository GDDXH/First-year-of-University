//f[i]=3*f[i-1]+2»òf(n) = 3n - 1
//ººÅµËþIII,µÝÍÆ 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int i;
	long long int num[40]={0,2,8,26};
	for(i=4;i<=35;i++)
	{
		num[i]=3*num[i-1]+2;
	}
	while(scanf("%d",&i)!=EOF)
	{
		printf("%lld\n",num[i]);
	}
	return 0;
}
