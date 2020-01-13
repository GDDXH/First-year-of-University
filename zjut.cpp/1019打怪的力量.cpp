#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int M;
		int m[10001];
		int a,b,c,d,e,power,amount; 
		int usetime=0;
		scanf("%d",&M);
		for(int i=0;i<M;i++)
		{
			scanf("%d",&m[i]);
		}
		sort(m,m+M);
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
		power=d;
		amount=M-1;
		while(usetime<=c&&power<e&&amount>=0)
		{
			usetime+=a+b;
			power+=m[amount];
			amount--;
		}
		if(power>=e)
			printf("Tyr is great!\n");
		else
			printf("Tyr is not so great!\n");
	}
	return 0;
}
