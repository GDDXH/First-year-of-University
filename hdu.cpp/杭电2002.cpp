#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
const double pi=3.1415927; 
int main()
{
	double r,result;
	while(scanf("%lf",&r)!=EOF)
	{
		result=pi*r*r*r*4/3;
		printf("%.3lf\n",result);
	}
	return 0;
}
