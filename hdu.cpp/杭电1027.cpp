#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
int main()
{
	int i,a[1010],m,n; 
	while (~scanf("%d %d",&m,&n))
	{
		memset(a,0,sizeof(a));
		for(i=1;i<=m;i++)
		{
			a[i]=i;
		} 
		while(--n)
		{
			next_permutation(a+1,a+m+1);
		}
		printf("%d",a[1]); 
		for(i=2;i<=m;i++)
		{
			printf(" %d",a[i]);
		}
		printf("\n");
	} 
	return 0;
}
