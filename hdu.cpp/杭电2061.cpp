#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
int main()
{
	int n,k;
	double credit,score,sum_credit,sum_score;
	bool flag;
	scanf("%d",&n);
	while(n--)
	{
		sum_credit=sum_score=0;
		flag=true;
		scanf("%d",&k);
		while(k--)
		{
			scanf("%*s%lf%lf",&credit,&score);
			if(score<60)
			{
				flag=false;
			}
			sum_credit+=credit;
			sum_score+=score*credit;
		}
		printf(flag?"%.2lf\n":"Sorry!\n",sum_score/sum_credit);
		if(n)
		{
			printf("\n");
		}
	}	
	return 0;
}
