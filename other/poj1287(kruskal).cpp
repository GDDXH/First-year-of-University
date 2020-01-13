#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 2500;
struct node{
	int x,y,distance;
}edge[maxn];
int n,m,set[maxn];
bool cmp(node a, node b)
{
	return a.distance<b.distance;
}
int find(int i)// 这是查询集合 
{
	return i==set[i]?i:set[i]=find(set[i]);
}
bool Union(int x,int y){  
    if(find(x)==find(y)) 
		return 0;  
    set[find(x)]=find(y);//这就是合并集合  
    	return 1;  
}  
void kruskal()
{
	int sum=0,i;
	for(i=1;i<=m;i++)
	 	if(Union(edge[i].x,edge[i].y))
            sum+=edge[i].distance;
	printf("%d\n",sum);	       		
}
int main()
{
	int i;
	while(scanf("%d",&n),n)
	{
		scanf("%d",&m);
		for(i=1;i<=n;i++)
			set[i] = i;
		for(i=1;i<=m;i++)
			scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].distance);
		sort(edge+1,edge+m+1,cmp);
		kruskal();
	}
	return 0;
}
