#include<iostream>
#include<string> 
using namespace std;
int fun(string);
int main()
{
	string s;
	while(cin>>s)
	{
		cout<<fun(s)<<endl;	
	}
	return 0;
}
int fun(string s)
{
	int p = s.find('+');
	if(p!=-1)
		return fun (s.substr(0,p)) + fun(s.substr(p+1));
	p = s.find('-');
	if(p!=-1)
		return fun (s.substr(0,p)) - fun(s.substr(p+1));
	p = s.find('*');
	if(p!=-1)
		return fun (s.substr(0,p)) * fun(s.substr(p+1));
	p = s.find('/');
	if(p!=-1)
		return fun (s.substr(0,p)) / fun(s.substr(p+1));
	int sum = 0;
	for(int i = s.size() - 1;i>=0;i--)
	{
		sum = sum*10+s[i]-'0';
	}
	return sum;
 } 
