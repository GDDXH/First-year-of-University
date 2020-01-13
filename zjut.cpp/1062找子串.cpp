#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1,s2;
	while(cin>>s1>>s2)
	{
		int i,flag=0;
		for(i=0;i<s1.size()-s2.size();i++)
		{
			string substring;
			substring=s1.substr(i,s2.size());
			if(substring==s2)
			{
				flag=1;
				break;
			}
		}
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
