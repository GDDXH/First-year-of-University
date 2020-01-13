#include<iostream>
#include<string>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string a,b;
		int i;
		cin>>a>>b;
		for(i=0;i<a.length()/2;i++)
		{
			cout<<a[i];
		}
		cout<<b;
		for(;i<a.length();i++)
		{
			cout<<a[i];
		}
		cout<<endl;
	}
 } 
