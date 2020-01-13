#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int N = 10000;
long int prime[N];
int  init_prime()  
{  
	memset(prime,0,sizeof(prime));  
	int i,j;
	for(i=2;i<sqrt(N*1.0);i++)
	{
		if(!prime[i])
			for(j=i*i;j<N;j+=i)
				prime[j] = 1;
	}
	for(i = 2,j = 0;i < N; i++)       
	    if(!prime[i])   
	        prime[j++] = i;
	return j; 
} 
int main()
{
	int m,a,b;
	int first=1; 
	int len = init_prime();
	while(scanf("%d%d%d",&m,&a,&b),m||a||b)
	{
		if(first)
			cout<<' ';
		first = 0;
		double limit = (double)a/b;
		double max=0;
		int i,j,p,q,temp;
		for(i = len-1;i>=0;i--)
		{
			if(prime[i]*2>m)
				continue;
			for(j = i;j>=0;j--)
			{
				if(prime[j]>m||prime[i]*prime[j]>m)
					continue;
				if((double)prime[j]/prime[i]<limit)
					break;
				if(prime[i]*prime[j]>max)
				{
					max =prime[i] *prime[j];
					p=prime[i];
					q=prime[j];	
				}
			}
		}
		printf("%d %d\n",q,p);
	}
	return 0;
} 
