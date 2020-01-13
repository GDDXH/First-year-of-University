//通过第一个人的匹配，然后要是第二个人选中了第一个人的搭档，要是第一个人还有其他选中就将搭档让个第二个人
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
const int maxn=550;
bool map[maxn][maxn];
bool flag[maxn];
int sign[maxn];
bool find (int k,int M);
int main()
{
	int K,M,N,i,j,a,b,result;
	while(cin>>K,K)
	{
		cin>>M>>N;
		memset(map,false,sizeof(map));
		memset(sign,-1,sizeof(sign));
		result=0;
		for(i=0;i<K;i++)
		{
			cin>>a>>b;
			map[a][b]=true;
		}
		for(i=1;i<=N;i++)
		{
			memset(flag,true,sizeof(flag));
			if(find(i,M))
				result++;
		}
		cout<<result<<endl;
	}
	return 0;
}
bool find (int k,int M)
{
	for(int i=1;i<=M;i++)
	{
		if(flag[i]&&map[i][k])	
		{
			flag[i]=false;
			if(sign[i]==-1||find(sign[i],M))
			{
				sign[i]=k;
				return true;
			}
		}
	}	
	return false;
}
