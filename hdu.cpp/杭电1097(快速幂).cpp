//一个整数N的M次方之后的末位数字
//需要使用快速幂，否则超时
//也可以使用数学规律，一个数的（4n+1）次方之后末尾和初始相同 
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int fun(int x,int y)  
{  
 	int t=1;  
    x%=10;  
    while(y>0)  
    {  
        if(y&1)  
        	t=t*x%10;   
        x=x*x%10;  
        y/=2;  
    }  
    return t;  
} 
int main()
{
	int i,a,b,result;
	while(~scanf("%d %d",&a,&b))
	{
		printf("%d\n",fun(a,b));  
	}
	return 0;
}
