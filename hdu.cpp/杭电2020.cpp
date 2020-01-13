#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
bool rule(int a,int b)
{
	return abs(a)>abs(b);
}
int main()
{
	int size,i,t;
	vector<int> a;
	while(scanf("%d",&size),size)
	{
		for(i=0;i<size;i++)
		{
			scanf("%d",&t);
			a.push_back(t);
		}
		sort(a.begin(),a.end(),rule);
		printf("%d",a[0]); 
		for(i=1;i<size;i++)
		{
			printf(" %d",a[i]);
		}
		printf("\n");
		a.clear(); 
	 } 
	 return 0;
}
