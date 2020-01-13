#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int i,counter=1;
	int T;
	cin>>T;
	while(T--)
	{
		string a,b,c;
		int temp=0,m=0;
		cin>>a>>b;
		cout<<"Case "<<counter++<<":"<<endl; 
		cout<<a<<" + "<<b<<" = ";
		if(a.length()<b.length())
		{
			string d;
			d=a;
			a=b;
			b=d;
		 } 
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		a+="0";
		b+="0";
		for(i=0;i<b.length();i++)
		{
			m=a[i]-'0'+b[i]-'0'+temp;
			c+=m%10+'0';
			temp=m/10;
		} 
		for(;i<a.length();i++)
		{
			m=a[i]-'0'+temp;
			c+=m%10+'0';
			temp=m/10;
		}
		reverse(c.begin(),c.end());
		if(c[0]=='0')
			{
		for(int j=1;j<c.length();j++)
		cout<<c[j];
		cout<<endl;
			}	
		else
		cout<<c<<endl;
		if(T) cout<<endl;  
	}	
 } 
