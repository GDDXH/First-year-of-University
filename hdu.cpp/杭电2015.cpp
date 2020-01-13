#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{	
    int n,m;  
    while(~scanf("%d %d",&n,&m))  
    {  
        int i,count = 0,temp = 0,sum = 0;  
        for (i=1;i<=n;i++)  
        {  
            count++; 
            temp+=2; 
            sum+=temp;  
            if(i==n) 
            {
                printf("%d\n",sum/count);  
            } 
			else 
			{
				if (count==m)  
            	{  
                	printf("%d ",sum/m);  
                	count=0; 
					sum=0;  
            	}
			}
        }  
    }  
    return 0;  
}
