#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double a;
		int b;
		scanf("%lf %d",&a,&b);
		if(int(a+0.5)==b)
			printf("Correct\n");
		else
			printf("Not Correct\n");
	}
	return 0;
}
