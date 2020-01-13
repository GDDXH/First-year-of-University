#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	//求走廊的重复利用次数 
	int	a[201]; 
	int T,N,i,j,max;
	scanf("%d",&T);
	while(T--)
	{
		int s,t;
		memset(a,0,sizeof(a));
		max=0;
		
		scanf("%d",&N);
		
		for(i=0;i<N;i++)
		{
			scanf("%d %d",&s,&t);
			if(s>t)//s,t的大小一定要注意 
			{
				s^=t;
				t^=s;
				s^=t;
			}
			s=(s+1)/2;
			t=(t+1)/2;
			for(j=s;j<=t;j++)
			{
				a[j]++;	
				if(a[j]>max)
					max=a[j];//这种方法比重新排序快很多 
			}
		}
		
		/*for(i=0;i<201;i++)这样也很快 
		{
			if(a[i]>max)
			max=a[i];
		}*/
		
		//sort(a,a+201);可见排序终究是要花很多时间 
		
		//	printf("%d\n",a[200]*10);
		printf("%d\n",max*10);
	}
}
