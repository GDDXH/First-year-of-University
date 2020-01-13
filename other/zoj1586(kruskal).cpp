#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
	int x,y,dis;
}; 
vector<node> edge;
int root[1005],QS[1005];
bool cmp(node a,node b){
	return a.dis<b.dis;
}
int find(int i){
	return i==root[i]?i:root[i]=find(root[i]); 
}
void merge(int i,int j)
{
	int root_i = find(i);
	int root_j = find(j);
	root[root_i] = root_j;
}
void kruskal()
{
	int sum=0,i,size=edge.size();
	for(i=0;i<size;i++)
		if(find(edge[i].x)!=find(edge[i].y))
		{
			merge(edge[i].x,edge[i].y);
			sum+=edge[i].dis;
		}
	printf("%d\n",sum);
}
int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	while(T--)
	{
		edge.clear();
		scanf("%d",&n);
		for(i=0;i<n;i++)
			root[i] = i;
		for(i=0;i<n;i++)
			scanf("%d",&QS[i]);
			
		for(i=0;i<n;i++)
		{
			node k;	
			for(j=0;j<n;j++)
			{
				k.x=i;
				k.y=j;
				scanf("%d",&k.dis);
				k.dis+=QS[i]+QS[j];
				edge.push_back(k);
			}
		}
		sort(edge.begin(),edge.end(),cmp);
		kruskal();
	}
	return 0;	
}
