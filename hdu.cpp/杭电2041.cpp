#include<iostream>
#include<cstdio>
#include<cstdlib> 
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	int size,i,a[50]={0,1,1,2};
	for(i=4;i<=40;i++)
	{
		a[i]=a[i-1]+a[i-2]; 
	}
	scanf("%d",&size);
	while(size--)
	{
		scanf("%d",&i);
		printf("%d\n",a[i]);
	 } 
	 return 0;
	
}
