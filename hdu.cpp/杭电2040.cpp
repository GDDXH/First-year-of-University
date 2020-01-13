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
	int a,b,i,sum1,sum2,size;
	bool flag;
	scanf("%d",&size);
	while(size--) 
	{
		scanf("%d %d",&a,&b);
		sum1=sum2=0; 
		for(i=1;i<=a/2;i++)
		{
			if(a%i==0)
			{
				sum1+=i;
			}
		}
		if(sum1!=b)
		{
			printf("NO\n");
			continue;
		}
		for(i=1;i<=b/2;i++)
		{
			if(b%i==0)
			{
				sum2+=i;
			}
		}
		if(sum2!=a)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
