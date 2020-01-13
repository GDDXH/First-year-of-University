#include<iostream>//尼科梅彻斯定理,可以得到这n个数的第一项就是：n^2-n+1,而且数列就是n个
#include<cstdio>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int First_item=n*n-n+1;
		printf("%d",First_item);
		for(int i=1;i<n;i++)
		{
			printf("+%d",First_item+2*i);
		}
		printf("\n");
	}
	return 0;
	
 } 
