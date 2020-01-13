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
	int i,size,t;
	double sum;
	while(scanf("%d",&size)!=EOF)
	{
		sum=0;
		for(i=0;i<size;i++)
		{
			scanf("%d",&t);
			a[i]=t;
		}
		sort(a,a+size);
		for(i=1;i<size-1;i++)
		{
			sum+=a[i];
		}
		printf("%.2lf\n",sum/(size-2));
	}
	return 0;
}
