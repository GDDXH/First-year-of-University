#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 210;
int lift[maxn] , flag[maxn] , map[maxn][maxn], step[maxn];
int N , A , B;
void Dijkstra(int A,int B)
{
	int i,j,min,position;
	for(i=1;i<=N;i++)
	{
		step[i] = map[A][i];
	}
	step[A] = 0;
	flag[A] = false;
	for(i=1;i<=N;i++)
	{
		min = 0x3f3f3f3f;
		for(j=1;j<=N;j++)
			if(step[j]<min&&flag[j])
			{
				position = j;
				min = step[j];
			}						
		if(min == 0x3f3f3f3f)  	break; 	
		flag[position] = false;
		for(j=1;j<=N;j++)  
        {  
            if(step[position]+map[position][j]<step[j]&&flag[j])  
			{
				step[j] = step[position] + map[position][j];
			}      
        }  
	}
}
int main()
{
	while(scanf("%d",&N),N)
	{
		scanf("%d %d",&A,&B);
		for(int i = 1; i<=N; i++)  
            for(int j = 1; j<=N; j++)  
                map[i][j] = 0x3f3f3f3f;  
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&lift[i]);
			flag[i] = true;
			if(i+lift[i]<=N)
				map[i][i+lift[i]] = 1;
			if(i-lift[i]>0)
				map[i][i-lift[i]] = 1;
		}
		Dijkstra(A,B);
		printf("%d\n",step[B]==0x3f3f3f3f?-1:step[B]);
	} 
	return 0;
 } 
