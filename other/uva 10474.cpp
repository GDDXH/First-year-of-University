#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[10100];
int main()
{
	int i,j,n,m,t,amout=1;
	while(scanf("%d %d",&n,&m),n||m)
	{
		printf("CASE# %d:\n",amout++);
		memset(a, 0, sizeof(a));  
		for(i=0;i<n;i++)
		{
			scanf("%d",&t);	
			a[t]++;
		}
		while(m--)
		{
			scanf("%d",&t);
			if(a[t])
			{
				int count=0;
				for(i=0;i<t;i++)
				{
					count+=a[i];
				}
				printf("%d found at %d\n",t,count+1);
			}
			else
			{
				printf("%d not found\n",t);
			}
		}
	}
	return 0;
}
