#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 205;
int lift[maxn];
bool visit[maxn];
int N,A,B;
struct node
{
	int step , location; 
};
bool check(int i)
{
	if(i>=1&&i<=N)
		return true;
	return false;
}
int bfs()
{
	queue<node> store;
	node k,next_k;
	k.step = 0;
	k.location = A;
	visit[k.location] = false;
	store.push(k);
	while(!store.empty())
	{
		k = store.front();
		store.pop();
		if(k.location == B)
		{
			return k.step;
		}
		for(int i=-1;i<=1;i+=2)
		{
			next_k.step = k.step+1;
			next_k.location = k.location + lift[k.location] * i;
			if(check(next_k.location)&&visit[next_k.location])
			{
				visit[next_k.location] = false;
				store.push(next_k);
			} 
		}
	} 
	return -1;	
}
int main()
{
	int i,result;
	while(scanf("%d",&N),N)
	{
		scanf("%d %d",&A,&B);
		for(i=1;i<=N;i++)
		{
			scanf("%d",&lift[i]);
			visit[i] = true;
		}
		result = bfs();
		printf("%d\n",result);
	}
}
