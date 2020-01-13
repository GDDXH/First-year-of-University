/*考虑一个集合 An = { 1, 2, ..., n}。比如，A1={1}，A3={1,2,3}。
我们称一个非空子集元素的排列为一个子集序列。对所有的子序列按字典顺序排序。
你的任务就是给出第m个子序列。*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int n,i,k,s[30];//s[i]是第i组的初始首元素 
	long long int m,g[21]={0,1,2,5};//g[i]是每组的个数
	for(i=4;i<21;i++)
	{
		g[i]=(i-1)*g[i-1]+1;
	}
	while(cin>>n>>m)
	{
		for(i=0;i<22;i++)
		{
			s[i]=i;		
		}
		while(n>0&&m>0)
		{
			k=m/g[n]+(m%g[n]>0?1:0);
			cout<<s[k];
			for(i=k;i<=n;i++)
			{
				s[i]=s[i+1];//这里s[i]++就是wrong不理解 
			}
			m-=((k-1)*g[n]+1);
			putchar(m==0?'\n':' ');  
			n--;
		}	
	}
	return 0;
} 
