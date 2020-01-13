//求N个数的最小公倍数 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int gcd(int m, int n) ; 
int main()
{
	int size,i,t,a[100];
	while(scanf("%d",&size)!=EOF)
	{
		for(i=0;i<size;i++)
		{
			scanf("%d",&a[i]);
		}
		t=a[0];
		for(i=1;i<size;i++)
		{
			t=t/gcd(t,a[i])*a[i];//t*a[i]/gcd(t,a[i])
		}
		printf("%d\n",t);
	}
}
int gcd(int m, int n)  
{  
	int t;
    if(m<n)
    {
    	m^=n;
   		n^=m;
   		m^=n;
	}
	while(t=m%n)
	{
		m=n;
		n=t;
	}
	return n;		
}  
