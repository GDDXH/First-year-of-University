#include<iostream>
#include<cstdio>
#include<cstdlib> 
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	int i,m,n,len;
	char a[100];
	bool flag;
	while(cin>>m>>n)
	{
		memset(a,0,sizeof(a));
		flag=false;
		if(m<0)
		{
			m=-m;
			flag=true;
		}
		for(i=0;m;i++)
		{
			if(m%n>=10)
				a[i]=m%n+55;
			else
				a[i]=m%n+48; 
			
			m=m/n;	
		}
		if(flag)
			cout<<"-";
		for(i--;i>=0;i--)
		{
			cout<<a[i];
		}
		cout<<endl; 
	 } 
	 return 0;
}
