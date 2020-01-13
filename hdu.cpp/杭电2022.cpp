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
	int m,n,i,j,k;
	while(~scanf("%d %d",&m,&n))
	{
		int max=0,x,y;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&k);
				if(abs(max)<abs(k))
				{
					max=k;
					x=i;
					y=j;
				}	
			}
		}	
		printf("%d %d %d\n",x,y,max);	
	}	
	return 0; 
}
