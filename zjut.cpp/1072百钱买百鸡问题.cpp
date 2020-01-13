#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int i,j,k;
	for(i=0;i<34;i++)
	{
		for(j=0;j<51;j++)
		{
			k=100-i-j;
			if(k%3==0&&3*i+2*j+k/3==100)
			{
				printf("%d %d %d\n",i,j,k);
			}
		}
	}
	return 0;
}
