#include<iostream>  //³¬Ê± 
#include<algorithm>
#include<cstdio>  
using namespace std ; 
const int maxn = 2000;  
int T,N;  
int map[maxn][maxn];  
void Floyd() 
{  
    int i , j , k ;  
    for(k=1;k<=N;k++) 
	{  
        for(i=1;i<=N;i++) 
		{  
            for(j=1;j<=N;j++) 
			{                 
                if(map[i][j]>map[i][k]+map[k][j])
                	map[i][j]=map[i][k]+map[k][j];
            }  
        }  
    }  
}  
int main()
{  
    scanf("%d %d",&T,&N);  
    int a,b,c;  
    for(int i=1;i<=N;i++)
	{  
    	for(int j=1;j<=N;j++) 
		{  
			if(i==j)
				map[i][j]=0;
			else
            	map[i][j]=0x3f3f3f3f;  
        }  
    } 
    for(int i=1;i<=T;i++) 
	{  
        scanf("%d%d%d",&a,&b,&c);
        map[a][b]=map[b][a]=c;  
    }  
    Floyd();  
    printf("%d\n",map[1][N]);
    return 0;  
}
