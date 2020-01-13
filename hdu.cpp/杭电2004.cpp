#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int t;
	while(scanf("%d",&t)!=EOF)
	{
		if(t<0||t>100)
		{
			printf("Score is error!\n");
		}
		else if(t<60)
		{
			printf("E\n");
		}
		else if(t<70)
		{
			printf("D\n");	
		}
		else if(t<80)
		{
			printf("C\n");	
		}
		else if(t<90)
		{
			printf("B\n");	
		}
		else if(t<=100)
		{
			printf("A\n");	
		}
	} 
	return 0;
}
