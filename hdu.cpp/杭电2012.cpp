
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
bool isprime(int a);
int main()
{
	int res,i,x,y;
	bool flag;
	while(scanf("%d%d",&x,&y))
	{
		flag=true;
		if(x==0&&y==0)
		{
			break;
		}
		for(i=x;i<=y;i++)
		{
			res=i*i+i+41;
			if(isprime(res))
			{
				flag=false;
				break;
			} 
		}
		if(flag)
			printf("OK\n");
		else
			printf("Sorry\n");
	}
}
bool isprime(int a)
{
	for(int i=2;i*i<=a;i++)
	{  
		if(a%i==0) return 1;  
	}  
	return 0;   
}
