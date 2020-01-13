//F(n)=min(2*F(n-r)+2^r-1)，（1≤r≤n）  
//四根柱子的汉诺塔问题 
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
	int i,j,n;
	long long int move_number[70]={0,1,3,5};
	for(i=4;i<=64;i++)
	{
		int Min=(1<<31)-1;
		for(j=1;j<i;j++)
		{
			Min=min(2*move_number[j]+pow(2.0,i-j)-1,Min*1.0);
		}
		move_number[i]=Min;
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",move_number[n]);
	}
	return 0;
}
