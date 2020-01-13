#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 110;
const int inf  = 0x3f3f3f3f;
int N,map[maxn][maxn];
void prim()
{
	int i,j,dis[maxn],visit[maxn],min_distance,sign;
	for(i=1;i<=N;i++){
		dis[i] = map[1][i];
		visit[i] = 1;
	}	
	dis[1] = 0;
	visit[1] = 0;
	for(i=1;i<N;i++)
	{
		min_distance = inf;
		for(j=1;j<=N;j++)
			if(dis[j]<min_distance&&visit[j]){
				min_distance = dis[j];	
				sign = j; 
			}
		visit[sign] = 0;
		for(j=1;j<=N;j++){
			if(dis[j]>map[sign][j]&&visit[j])
			dis[j] = map[sign][j];	
		}		
	}
	for(i=1,dis[0]=0;i<=N;i++)
	{
		dis[0]+=dis[i];
	}
	printf("%d\n",dis[0]);
}
int main()
{
	int i,j,k;

	scanf("%d",&N);
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
		{
			scanf("%d",&k);
			map[i][j]=map[j][i]=k;
		}
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d",&i,&j);
		map[i][j] = 0;
		map[j][i] = 0;
	}
	prim();	
	return 0;
}
