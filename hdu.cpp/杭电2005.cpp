#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
const int number[13]={0,0,31,59,90,120,151,181,211,242,273,303,334};
bool f(int a); 
int main()
{
	int year,month,day,result;
	while(~scanf("%d/%d/%d",&year,&month,&day))
	{
		if(f(year)&&month>2)
		{
			result=1;
		}
		else 
			result=0;
		printf("%d\n",result+number[month]+day);
	}
}
bool f(int a)
{
	if(a%4==0&&a%100!=0||a%400==0)
		return true;
	else
		return false;
 } 
