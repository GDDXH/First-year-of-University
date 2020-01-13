#include<iostream>
#include<algorithm>
using namespace std;
int n,k;
int cheese[110][110];
int result[110][110];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int move(int x , int y)
{
	int next_x,next_y,i,j,temp_max = 0;
	if(result[x][y]==0)
	{
		for(i=1;i<=k;i++)
		{
			for(j=0;j<4;j++)
			{
				next_x = x + dx[j]*i;
				next_y = y + dy[j]*i;
				if(next_x>=0&&next_y>=0&&next_x<n&&next_y<n&&cheese[x][y]<cheese[next_x][next_y])
				{
				temp_max = max(temp_max,move(next_x,next_y));	
				}	
			}
		}
		result[x][y] = cheese[x][y]+temp_max;	
	}	
	return result[x][y];
}
int main()
{
	int i,j;
	while(~scanf("%d %d",&n,&k))
	{
		if(n==-1&&k==-1)
		{
			break;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&cheese[i][j]);
				result[i][j] = 0;
			}
		}
		move(0,0);
		cout<<result[0][0]<<endl;
	}
	return 0;
}
