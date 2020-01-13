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
	int n,i,result;
	while(scanf("%d",&n)!=EOF)
	{
		result=1;
		for(i=1;i<n;i++)
		{
			result=(result+1)*2;
		}
		printf("%d\n",result);
	}
	return 0;
}
