#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
int main()
{
	int L,N,C,T,VR,VT1,VT2,p[110],i,j,len;  
	double dp[110],time,min;
	while(scanf("%d",&L)!=EOF) 
	{      
		scanf("%d %d %d",&N,&C,&T);  
        scanf("%d %d %d",&VR,&VT1,&VT2);  
        for(i = 1; i <= N; i++)  
        {
        	scanf("%d", &p[i]);  
		}
	    p[0] = 0;
		p[N + 1] = L;   
        dp[0] = 0;  
		for(i=1;i<N+2;i++)  
		{
			dp[i]=1000000;
			for(j=0;j<i;j++)
			{
				len=p[i]-p[j];
				if(len>C)
				{
					time = 1.0*C/VT1+(len-C+0.0)/VT2;   
				}
				else
				{
					time = 1.0*len/VT1;
				}
				time+=dp[j];
				if(j)
					time+=T;
				if(dp[i]>time)
					dp[i]=time;
			}
		} 
	    if(1.0 * L / VR < dp[N + 1])  
            printf("Good job,rabbit!\n");  
        else  
            printf("What a pity rabbit!\n");  
        }
	return 0; 
}
