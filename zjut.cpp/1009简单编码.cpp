#include<iostream>
#include<string>
void change(char &a)
{
	if(a=='A'||a=='W'||a=='F')                a='I';
	else if(a=='C')					          a='L';
	else if(a=='M')                           a='o';
	else if(a=='S')                           a='v';
	else if(a=='D'||a=='P'||a=='G'||a=='B')   a='e';
	else if(a=='L')                           a='Y';
	else if(a=='X')                           a='u';
}
using namespace std;
int main()
{
	string s;
	while(getline(cin,s),s!="END")
	{
		for(int i=0;i<s.size();i++)
		{
			change(s[i]);
		}
		cout<<s<<endl;
	}
}
