#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		int flag=0;
		s+=s[0];
		s+=s[1];
		for(int i=0;i<s.size()-2;i++)
		{
			if(s[i]=='3'&&s[i+1]=='3'&&s[i+2]=='3')
			flag=1;
		}
		if(s.size()<=4)
			flag=0;
		if(flag)
		cout<<"Lucky"<<endl;
		else
		cout<<"Sad"<<endl;
	}
}
