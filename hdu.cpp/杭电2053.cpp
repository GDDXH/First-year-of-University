//题目的意思是，初始化全部数据为零，i从1开始递增，每次改变编号为i倍数的灯的状态（0或1），输入N，判断最后编号为N的灯的最终状态。
//也就是说，当i增长的超过N时，N的值不会再改变。该题就是求N的因数的奇偶性。
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
	int i,n;
    while(cin>>n)
	{
        int sum=1;
        for(i=1;i<=n/2;i++)
        {
        	if(n%i==0) sum++;
		}
        if(sum%2==0) 
			cout<<'0'<<endl;
        else 
			cout<<'1'<<endl;
    }

}
