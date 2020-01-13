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
	int i,size,a[50]={3,4,6} ; 
	for(i=3;i<=30;i++)
	{
		a[i]=(a[i-1]-1)*2; 
	} 
	scanf("%d",&size);
	while(size--)
	{
		scanf("%d",&i);
		printf("%d\n",a[i]);
	}
	return 0;
}
