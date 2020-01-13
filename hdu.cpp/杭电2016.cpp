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
	int a[110];
	int size,t,i,k;
	while(scanf("%d",&size),size)
	{
		for(i=0,k=0;i<size;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<a[k])              
            {
            	k=i;
			}   
		} 
		if(k)
		{
			t=a[0];
			a[0]=a[k];
			a[k]=t;
		}
		printf("%d",a[0]);
		for(i=1;i<size;i++)
		{
		printf(" %d",a[i]);
		}
		printf("\n");
         
	}
}
