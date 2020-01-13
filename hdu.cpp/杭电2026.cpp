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
	string s;
	int i;
	while(getline(cin,s))
	{
		int len=s.size();
		s[0]-=32;
		for(i=1;i<len;i++)
		{
			if(s[i]==' ')
			{
				s[i+1]-=32;
			}
		}
		cout<<s<<endl;
	 } 
	 return 0;
}
