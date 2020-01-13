#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct inverted_sort
{
	int original;
	int inverted;
};
int f(int a)//µ¹ÖÃº¯Êı
{
	int b=0;
	while(a)
	{
		b=b*10+a%10;
		a/=10;
	}
	return b; 
} 
bool rule(inverted_sort a,inverted_sort b)
{
	return a.inverted<b.inverted;
}
int main()
{
	int T,size;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&size);
		vector<inverted_sort> figure(size);
		for(int i=0;i<size;i++)
		{
			scanf("%d",&figure[i].original);
			figure[i].inverted=f(figure[i].original);
		}
		sort(figure.begin(),figure.end(),rule);
		for(int i=0;i<size-1;i++)
		{
			printf("%d ",figure[i].original);
		} 
		printf("%d\n",figure[size-1].original);
	}
	return 0;
}
