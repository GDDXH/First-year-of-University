#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int number[1510]={0,1},m2=1,m3=1,m5=1,i;
	for(i=2;i<=1500;i++)
	{
		number[i] = min(number[m2]*2,min(number[m3]*3,number[m5]*5));
		if(number[i]==2*number[m2])	m2++;
		if(number[i]==3*number[m3])	m3++;
		if(number[i]==5*number[m5])	m5++;
	}
	while(scanf("%d",&i)!=EOF)
	{
		printf("The %dth ugly number is %d.\n",i,number[i]);
	}
	return 0;
}
