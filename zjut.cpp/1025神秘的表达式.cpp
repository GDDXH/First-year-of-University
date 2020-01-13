#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int z,u,t;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&z,&u,&t);
		if(z+u==t)
			printf("+\n");
		else if(z-u==t)
			printf("-\n");
		else if(z*u==t)
			printf("*\n");
		else if(z/u==t)
			printf("\\\n");
	}
	return 0;
 } 
