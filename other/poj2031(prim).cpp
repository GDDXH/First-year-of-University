#include<iostream>//最小生成树，prim算法 
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
const int maxn = 105;
const int inf  = 0x3f3f3f3f;
int n;
struct node{
	double x,y,z,r;
}ball[maxn];
double map[maxn][maxn];
double handle(int i,int j)
{
	double r_sum = ball[i].r + ball[j].r;
	double x_distance = ball[i].x - ball[j].x;
	double y_distance = ball[i].y - ball[j].y;
	double z_distance = ball[i].z - ball[j].z;
	double center=sqrt(x_distance*x_distance+y_distance*y_distance+z_distance*z_distance);
	return center-r_sum>0?center-r_sum:0;
}
void prim()
{
	int i,j,sign,visit[maxn];
	double min_distance,dis[maxn];
	for(i=1;i<=n;i++){
		dis[i] = map[1][i];
		visit[i] = 1;
	}
	visit[i] = 0;
	for(i=1;i<n;i++)
	{
		min_distance = inf;
		for(j=1;j<=n;j++)
			if(dis[j]<min_distance&&visit[j])
			{
				min_distance = dis[j];
				sign = j;
			}
		visit[sign] = 0;
		for(j=1;j<=n;j++)
			if(dis[j]>map[sign][j]&&visit[j])
				dis[j] = map[sign][j];
	}
	for(i=1,dis[0]=0;i<=n;i++)	
		dis[0]+=dis[i];
	printf("%.3lf\n",dis[0]);
		
}
int main()
{
	int i,j;
	while(scanf("%d",&n),n)
	{
		for(i=1;i<=n;i++){
			scanf("%lf%lf%lf%lf",&ball[i].x,&ball[i].y,&ball[i].z,&ball[i].r);
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				if(i==j)
					map[i][j] = map[j][i] = 0;
				else
					map[i][j] = map[j][i] =handle(i,j);
			}
		prim();
	}
	return 0;
	
}
