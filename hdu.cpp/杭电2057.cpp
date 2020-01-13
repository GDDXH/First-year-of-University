#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
int main()
{
	long long int a,b;
	while(cin>>hex>>a>>b)
	{
	if(a+b<0)
     	cout<<'-'<<setiosflags(ios::uppercase)<<hex<<-a-b<<endl;
    else
    	 cout<<setiosflags(ios::uppercase)<<hex<<a+b<<endl;
	 } 
	 return 0;
}
