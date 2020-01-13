#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,set[105];//初始每一个点就是一个集合，然后不断并查集； 
struct node{
	int x,y,distance;
};
vector<node> edge;
bool cmp(node a, node b){
	return a.distance<b.distance;
}
int find_root(int i)// 查询集合，查询其父节点 
{
	return i==set[i]?i:set[i]=find_root(set[i]);
 } 
void merge(int i,int j)
{
	int root_i = find_root(i);
	int root_j = find_root(j);
	set[root_i] = root_j; 
}
void kruskal()
{
	int sum=0,i,size=edge.size();
	for(i=0;i<size;i++)
		if(find_root(edge[i].x)!=find_root(edge[i].y))
		{
			merge(edge[i].x,edge[i].y);
			sum+=edge[i].distance;
		}
	printf("%d\n",sum);
}
int main() 
{
	int i,j,Q; 
	for(i=0;i<105;i++)//初始化 
	{
		set[i] = i;
	}
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		node k;
		k.x=i;
		for(j=0;j<n;j++)
		{
			k.y=j;
			scanf("%d",&k.distance);
			edge.push_back(k);//不用vector，则需声明一个计数器 
		}
	}
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d %d",&i,&j);
		merge(i-1,j-1);
	}
	sort(edge.begin(),edge.end(),cmp);
	kruskal();
	return 0;	
}
