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
	int i,n;
	int a[1000];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;n>0;i++)
		{
			a[i]=n%2;
			n/=2;
		} 
		for(i--;i>=0;i--)
		{
			printf("%d",a[i]);
		}
		printf("\n");
	}
	return 0;
}
