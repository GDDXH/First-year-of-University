#include<iostream>
#include<cstdio>
using namespace std;
const int dx[8]={-1,-1,0,1,1,1,0,-1};
const int dy[8]={0,1,1,1,0,-1,-1,-1};
char oil[101][101];
int m,n;
void dfs(int a,int b)
{
	int i,x,y;
	for(i=0;i<8;i++)
	{
		x=a+dx[i];
		y=b+dy[i];
		if(x<0||x>=m||y<0||y>=n||oil[x][y]=='*')
			continue;
		oil[x][y]='*';
		dfs(x,y);  
	}	
}
int main()
{
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		if(m==0)
			break;
		int i,j, count=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>oil[i][j];
			}	
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(oil[i][j]=='@')
				{
					dfs(i,j);
					count++;
				}
			}	
		}
		printf("%d\n",count);
	}
	return 0;	
}

