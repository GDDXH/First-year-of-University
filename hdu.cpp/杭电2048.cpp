//该题为错排题，直接套用错排公式 f(1)=0,f(2)=1;f(n)=(n-1)(f(n-1)+f(n-2))
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
	long long int a[50]={0,0,1,2},b[50]={1,1,2,6};
	int i,size;
	for(i=4;i<=20;i++)
	{
		a[i] = (i-1)*(a[i-1]+a[i-2]);
		b[i] = b[i-1]*i;
	}
	scanf("%d",&size);
	while(size--)
	{
		scanf("%d",&i);
		printf("%.2lf%%\n",a[i]*100.0/b[i]);
	}
	return 0;
}
