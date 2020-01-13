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
	int base,time,i,ans;
 	while (scanf("%d %d",&base,&time)!=EOF)
 	{
  		base%=10;
 	 	time%=4;
  		ans=base*base*base;
  		for(i=0;i<=time;i++)
   			ans*=base;
  		printf("%d\n",ans%10);
 }
}
