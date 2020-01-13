#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int i,j,sum;
	int count=0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			sum=10000+i*1000+j*100+47;
			if(sum%57==0||sum%67==0)
			{
				printf("%d\n",sum);
				count++;
			}
		}
	}
	printf("%d\n",count);
}
