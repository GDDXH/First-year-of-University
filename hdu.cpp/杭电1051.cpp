#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<set>
#include<cctype>
#include<sstream>
using namespace std;
struct wooden_sticks
{
	int length,weight;
	bool flag;
}wood[5010];;
bool rule (wooden_sticks a,wooden_sticks b)
{
	if(a.length!=b.length)
		return a.length<b.length;
	else
		return a.weight<b.weight;
}
int main()
{
	int T,n,time,i,j,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&wood[i].length,&wood[i].weight);
			wood[i].flag=false;
		}

		sort(wood,wood+n,rule);
	
		for(i=0,time=0;i<n;i++)
		{
			if(wood[i].flag)
			{
				continue;
			}
		
			for(j=i+1,k=i,time++;j<n;j++)
			{
				if(wood[j].weight>=wood[k].weight&&!wood[j].flag)
				{
					wood[j].flag=true;
					k=j;
				}
			}
		}
		cout<<time<<endl;
	}
	return 0;
}
