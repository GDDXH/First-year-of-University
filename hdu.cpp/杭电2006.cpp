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
	int size,i,temp,result;
	while(scanf("%d",&size)!=EOF)
	{
		result=1;
		for(i=0;i<size;i++)
		{
			scanf("%d",&temp);
			if(temp%2!=0)
				result*=temp;
		}
		printf("%d\n",result);
	}
}
