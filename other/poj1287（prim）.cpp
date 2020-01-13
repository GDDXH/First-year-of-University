#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 55;
const int inf  = 0x3f3f3f3f;
int P,R,map[maxn][maxn];
void prim()
{
	int i,j,dis[maxn],visit[maxn],min_distance,sign;
	for(i=1;i<=P;i++){
		dis[i] = map[1][i];
		visit[i] = 1;
	}	
	dis[1] = 0;
	visit[1] = 0;
	for(i=1;i<P;i++)
	{
		min_distance = inf;
		for(j=1;j<=P;j++)
			if(dis[j]<min_distance&&visit[j]){
				min_distance = dis[j];	
				sign = j; 
			}
		visit[sign] = 0;
		for(j=1;j<=P;j++){
			if(dis[j]>map[sign][j]&&visit[j])
			dis[j] = map[sign][j];	
		}		
	}
	for(i=1,dis[0]=0;i<=P;i++)
		dis[0]+=dis[i];
	printf("%d\n",dis[0]);
}
int main()
{
	int i,j,a,b,c;
	while(scanf("%d",&P),P)
	{
		scanf("%d",&R);
		for(i=1;i<=P;i++)
			for(j=1;j<=P;j++){
				if(i==j) 
					map[i][j] = 0;
				else     
					map[i][j] = inf;
			}
		for(i=1;i<=R;i++){
			scanf("%d %d %d",&a,&b,&c);
			if(map[a][b]>c)
				map[a][b]=map[b][a]=c;
		}
		prim();	
	}
	return 0;
}
