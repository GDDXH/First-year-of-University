#include<iostream>//»¬Ñ© £¬DP»ò¼ÇÒä»¯ËÑË÷ 
#include<algorithm>
#include<cstdio>
using namespace std;
int R,C;
int high[110][110],result[110][110];
int ski(int x ,int y)
{
	int w,a,s,d;
	w=a=s=d=0;
	if(result[x][y] != 0)
	{
		return result[x][y];
	}
	if(x>0&&high[x][y]>high[x-1][y])
	{
		w = ski(x-1,y);
	}
	if(x<R-1&&high[x][y]>high[x+1][y])
	{
		s = ski(x+1,y);
	}
	if(y>0 &&high[x][y]>high[x][y-1])
	{
		a = ski(x,y-1);
	}
	if(y<C-1&&high[x][y]>high[x][y+1])
	{
		d = ski(x,y+1);
	}
	return result[x][y] = max(max(w,s),max(a,d))+1;
}
int main()
{
	int i,j,max_result;
	while(~scanf("%d %d",&R,&C))
	{
		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
			{
				scanf("%d",&high[i][j]);
				result[i][j] = 0;
			}
		}
		for(i=max_result=0;i<R;i++)
		{
			for(j=0;j<C;j++)
			{
				ski(i,j);
				if(result[i][j]>max_result)
				max_result=result[i][j];
				
			}
		}
		/*for(i=max_result=0;i<R;i++)
		{
			for(j=0;j<C;j++)
			{
				if(result[i][j]>max_result)
					max_result = result[i][j];
			}
		}*/
		cout<<max_result<<endl;
		
	}
}
