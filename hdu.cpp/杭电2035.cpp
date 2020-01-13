//一个整数N的M次方之后的后三位数字
//此题简单，每次取余即可 
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,b,i,result;
	while(~scanf("%d %d",&a,&b))
	{
		if(a==0&&b==0)
		{
			break;
		}
		a%=1000;
		result=a;
		for(i=1;i<b;i++)
		{
			result*=a;
			result%=1000;
		}
		printf("%d\n",result%1000);
	}
}
