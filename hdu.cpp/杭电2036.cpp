//求多边形的面积，划分为一个个三角形，运用向量运算 
#include<iostream>
#include<cstdio>
#include<cstdlib> 
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	int x[110],y[110],size,i;
	while(scanf("%d",&size))
	{
		double sum=0;
		if(size==0)
		{
			break;
		}
		for(i=0;i<size;i++)  
        {  
            scanf("%d %d",&x[i],&y[i]);  
        } 
        for(i=1;i<size-1;i++)
        {
           sum+=(x[i]-x[0])*(y[i+1]-y[0])-(x[i+1]-x[0])*(y[i]-y[0]);
		}
		printf("%.1lf\n",sum/2); 
	} 
	return 0;
}
