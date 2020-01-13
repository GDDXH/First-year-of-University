#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int p;
	while(getline(cin,s))
	{
		p = s.find_first_not_of(' ');
		if(p == string::npos)
			continue;
		if(s.substr(p,2)=="//")
			continue;
		p = s.find("//");
		if(p == string::npos)
			cout<<s<<endl; 
		else
		{
			p = s.find_last_not_of(' ',p-1);
			cout<<s.substr(0,p+1)<<endl;
		}
	}
}
