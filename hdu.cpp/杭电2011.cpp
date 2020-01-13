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
	int size,n,i;
	double result;
	scanf("%d",&size);
	while(scanf("%d",&n)!=EOF)
	{
		result=0;
		for(i=1;i<=n;i++)
		{
			if(i%2!=0) 
				result+=1.0/i;
			else
				result-=1.0/i;
		}
		printf("%.2lf\n",result); 
	} 	
	return 0; 
}
