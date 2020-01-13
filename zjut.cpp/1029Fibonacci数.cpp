#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int array[50]={0,1};
	for(int i=2;i<47;i++)
	{
		array[i]=array[i-1]+array[i-2];
	}
	int t;
	while(scanf("%d",&t)!=EOF)
	{
		printf("%d\n",array[t]);
	}
	return 0;
}
