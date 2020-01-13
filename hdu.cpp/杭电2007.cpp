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
	int m,n,i,result_1,result_2;
	while(~scanf("%d%d",&m,&n))
	{
		result_1=0;
		result_2=0;
		if(m>n)
		{
			m^=n;
			n^=m;
			m^=n;
		}
		for(i=m;i<=n;i++)
		{
			if(i%2==0)
				result_1+=i*i;
			else
				result_2+=i*i*i;
		}
		printf("%d %d\n",result_1,result_2);
	}
}
