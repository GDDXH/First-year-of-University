#include<iostream>//最短路问题，or dfs
#include<cmath>
#include<algorithm> 
using namespace std;
int dfs(int map[30][30],int  pre,int  start,int dis);
int main()
{
	int n;
	cin>>n;
	int map[30][30];
	for(int i=1;i<=26;i++)
		for(int j=1;j<=26;j++)
			map[i][j] = 0;
	for(int i=0;i<n;i++)
	{
		int d;
		char u,v;
		cin>>u>>v>>d;
		map[u-'A'+1][v-'A'+1] = d;
		map[v-'A'+1][u-'A'+1] = d; 
	}
	int a = dfs(map,0,1,0);
	int b = dfs(map,0,2,0);
	int c = dfs(map,0,3,0);	
	if(a==min(a,min(b,c)))
		cout<<"A "<<min(a,min(b,c))<<endl;
	else if(b==min(a,min(b,c)))
		cout<<"B "<<min(a,min(b,c))<<endl;
	else
		cout<<"C "<<min(a,min(b,c))<<endl;	
} 
int dfs(int map[30][30],int  pre,int  start,int dis)
{
 	int temp,min=0x3f3f3f3f;
 	if(start==('T'-'A'+1))
 		return dis;
 	for(int i=1;i<=26;i++)
	{
		if(pre!=i&&map[i][start])
		{
			temp = dfs(map,start,i,dis+map[i][start]);	
			if(temp<min)
				min =temp;
		} 		
	} 
	return min;	
}

