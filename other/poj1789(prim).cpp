#include<iostream>
#include<cstdio>
using namespace std;
const int maxn =2005;
const int inf =0x3f3f3f3f;
char str[maxn][10];
int map[maxn][maxn],N;
void prim()
{
	int vis[maxn],dis[maxn],sign,min,i,j;
	for(int i=1;i<=N;i++){
		dis[i] = map[1][i];
		vis[i] = 1;
	}
	vis[1] = 0;
	for(i=1;i<N;i++)
	{
		min = inf;
		for(j=1;j<=N;j++){
			if(dis[j]<min&&vis[j])
			{
				min =dis[j];
				sign = j;
			}
		}
		vis[sign] = 0;
		for(j=1;j<=N;j++){
			if(dis[j]>map[sign][j]&&vis[j])
				dis[j] = map[sign][j];
		}
	}
	for(i=1,dis[0]=0;i<=N;i++)
		dis[0]+=dis[i];
	printf("The highest possible quality is 1/%d.\n" , dis[0]) ;	
}
int main()
{
	while(scanf("%d",&N),N)
	{
		int i,j;
		for(i=1;i<=N;i++)
		{
			scanf("%s",&str[i][0]);
			for(j=1;j<=i;j++)
			{
				int ans = 0;
				for(int k=0;k<7;k++)
					if(str[i][k]!=str[j][k])
						ans++;
				map[i][j] = map[j][i] =ans;
			}
		}
		prim();	
	 } 
	return 0;
 } 
