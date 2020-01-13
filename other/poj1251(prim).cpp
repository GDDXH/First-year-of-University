#include<iostream>
using namespace std;
const int inf = 0x3f3f3f3f;
int map[30][30],N;
void prim()
{
	int i,j,min,sign,vis[30],dis[30];
	for(i=0;i<N;i++){
		dis[i] = map[0][i];
		vis[i] = 1;
	}
	for(i=1;i<N;i++)
	{
		min = inf;
		for(j=0;j<N;j++)
			if(dis[j]<min&&vis[j])
			{
				min = dis[j];
				sign = j;
			}
		vis[sign] = 0;
		for(j=0;j<N;j++){
			if(dis[j]>map[sign][j]&&vis[j])
			dis[j] = map[sign][j];
		}
	 } 
	for(i=1;i<N;i++)
		dis[0]+=dis[i];
	printf("%d\n",dis[0]);
}
 
int main()
{
	int i,j,k,size;
	char a[2],b[2];
	while(scanf("%d",&N),N)
	{
		for(i=0;i<N;i++) //³õÊ¼»¯ 
            for(j=0;j<N;j++)  
                if(i==j)  
                    map[i][j]=0;  
                else  
                    map[i][j]=inf;  
                    
		for(i=1;i<N;i++){
			scanf("%s %d",a,&size);
			for(j=0;j<size;j++){
				scanf("%s %d",b,&k);
				map[a[0]-'A'][b[0]-'A']=map[b[0]-'A'][a[0]-'A']=k;
			}
		}	 
		prim(); 
	}
	return 0;
}
