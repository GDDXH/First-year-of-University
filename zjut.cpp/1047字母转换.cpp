#include<iostream>
#include<string>
using namespace std;
void change(char &c)
{
	if(isalpha(c))
	{
		if(c>='a'&&c<='z')
			c -=32;
		else
			c +=32;
	}
	return ; 
}
int main()
{
	string s;
	while(getline(cin,s))
	{
		int len = s.size();
		for(int i=0;i<len;i++)
		{
			change(s[i]);
		}
		cout<<s<<endl;
	}
	return 0;
 } 
