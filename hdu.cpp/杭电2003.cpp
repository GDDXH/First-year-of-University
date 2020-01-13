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
	double number;
	while(scanf("%lf",&number)!=EOF)
	{
		number=abs(number);
		printf("%.2lf\n",number);
	}	
	return 0;
}
