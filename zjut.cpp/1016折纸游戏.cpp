#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int array[100][100];
		int m,i,j;
		int flag=1;
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>array[i][j];
			}
		}
		for(i=0;i<m&&flag;i++)
		{
			for(j=0;j<m;j++)
			{
				if(array[i][j]!=array[i][m-j-1]||array[i][j]!=array[m-i-1][j])
				{
					flag=0;
					break;
				}
			}
		}
		if(flag)
			printf("yes\n");
		else
			printf("no\n");
		
	}
	return 0;
 } 
