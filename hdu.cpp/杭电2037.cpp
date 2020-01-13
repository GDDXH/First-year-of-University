#include<iostream>//½ñÄêÊî¼Ù²»AC 
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct data
{
	int a,b;
};
bool rule(data x , data y)
{
	return x.b<y.b;
}
int main()
{
	int size,i,k,result;
	data time[110];
	while(scanf("%d",&size),size)
	{
		
		for(i=0;i<size;i++)
		{
			scanf("%d %d",&time[i].a,&time[i].b);
		}
		
		sort(time,time+size,rule);

		for(i=0,result=1,k=0;i<size;i++)
		{
			if(time[i].a>=time[k].b)
			{
				result++;
				k=i;
			}
		}
		printf("%d\n",result);
	}
	return 0;
}
