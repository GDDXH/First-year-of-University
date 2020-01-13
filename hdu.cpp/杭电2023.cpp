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
	int i,j,m,n,a[50][10],count,sum;
	double	average1[50],average2[50];
	bool flag;
	while(~scanf("%d %d",&m,&n))
	{
		count=0;
		for(i=0;i<m;i++) 
		{
			for(j=0;j<n;j++)   
			{
				scanf("%d",&a[i][j]); 
			}
		}  
        for(i=0;i<m;i++)   
        {    
            sum=0;  
            for(j=0;j<n;j++)  
			{
				sum+=a[i][j];  
			}    
            average1[i]=1.0*sum/n;  
        } 
        for(j=0;j<n;j++)  
        {  
            sum=0;  
            for(i=0;i<m;i++)   
            {
            	sum+=a[i][j]; 
			} 
            average2[j]=1.0*sum/m;  
        }
        for(i=0;i<m;i++)  
        {  
            flag=true;   
            for(j=0;j<n;j++)   
                if(a[i][j]<average2[j])  
                {   
                    flag=false;   
                    break;   
                }   
            if(flag)  
                count++;  
        } 
        for(i=0;i<m-1;i++)
		{
			printf("%.2lf ",average1[i]);  
		  }    
        printf("%.2lf\n",average1[i]);   
        for(i=0;i<n-1;i++)  
        {
        	printf("%.2lf ",average2[i]);  
		  }
        printf("%.2lf\n",average2[i]);  
        printf("%d\n\n",count);  
	}
	return 0;
}
