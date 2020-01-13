#include<iostream>
#include<cstdio>
using namespace std;
int  prime[41]={
	0,
	0,1,1,0,1,
	0,1,0,0,0,
	1,0,1,0,0,
	0,1,0,1,0,
	0,0,1,0,0,
	0,0,0,1,0,
	1,0,0,0,0,
	0,1,0,0,0 
};
bool judge(int a[],int k,int new_number)
{
	if(!prime[a[k]+a[k-1]])
	{
		return false;
	}
	for(int i=1;i<k;i++)
	{
		if(a[i] == new_number)
			return false;
	}
	return true;
}
void permutation(int a[],int k,int n)
{
	if(n&1)
	{
		return;
	}
	if(k==n)
	{
		if(prime[a[0] + a[n-1]])
		{
			printf("%d",a[0]);
			for(int i=1;i<n;i++)  
    		{   
      			printf(" %d",a[i]);  
    		}  
     		printf("\n");  
		}		
	}
	else
	{
		for(int i=2;i<=n;i++)
		{
			a[k] = i;
			if(judge(a,k,i))
			{
				permutation(a,k+1,n);
			}
		}
	}
}
int main()
{
	int n,amout=1;
	while(scanf("%d",&n)!=EOF)
	{
		printf("Case %d:\n",amout++);
		int a[20] = {1};
		permutation(a,1,n);
		printf("\n");
	} 
	return 0;	
}
