#include<iostream>//ÊýËþ 
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int a[110][110];
	int C,N;
	
	scanf("%d",&C);
	
	while(C--)
	{
		int i , j;
		scanf("%d",&N);
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=i;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(i=N;i>1;i--)
		{
			for(j=1;j<i;j++)
			{
				a[i-1][j]=max(a[i][j],a[i][j+1])+a[i-1][j];
			}
		}
		cout<<a[1][1]<<endl;
	}
}
