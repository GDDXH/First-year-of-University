#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	typedef int count; 
	int i,t,len;
	count a,b,c,d,e;
	string s;
	cin>>t;
	getchar();
	while(t--)
	{
		a=b=c=d=e=0;
		getline(cin,s);
		len=s.size();
		for(i=0;i<len;i++)
		{
			if(s[i]=='a')
			a++;
			if(s[i]=='e')
			b++;
			if(s[i]=='i')
			c++;
			if(s[i]=='o')
			d++;
			if(s[i]=='u')
			e++;
		}
		cout<<"a:"<<a<<endl
			<<"e:"<<b<<endl
			<<"i:"<<c<<endl
			<<"o:"<<d<<endl
			<<"u:"<<e<<endl;		
		if(t>0)
		{
			cout<<endl;
			}	
	}
	return 0;
}
