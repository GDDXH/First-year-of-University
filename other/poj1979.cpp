#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char map[25][25]; 
int w,h,result;
void dfs(int x,int y)
{
	if(x>=0&&y>=0&&x<=h-1&&y<=w-1&&map[x][y]=='.')
	{
		result++;
		map[x][y] = '#';
	}
	else
		return ;
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
}
int main()
{
	int i,j;
	while(scanf("%d%d",&w,&h),w!=0)
	{
		result = 0;	
		memset(map, 0, sizeof(map)); 
		int x,y;
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				scanf("\n%c",&map[i][j]);
				if(map[i][j] == '@')
				{
					x=i;
					y=j;
				}
			}
		}
		map[x][y] ='.';
		dfs(x,y);	
		cout<<result<<endl;
	}
	return 0;
 } 
