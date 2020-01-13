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
	int i;
	int n[60]={0,1,2,3};
	for(i=4;i<55;i++)
	{
		n[i]=n[i-1]+n[i-3];
	}
	while(scanf("%d",&i),i)
	{
		printf("%d\n",n[i]);
	}
	return 0;
}
