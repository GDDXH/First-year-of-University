#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		sort(s.begin(),s.end());
		if(s[s.size()-1]>57||s[0]<48)
		{
		cout<<"No"<<endl;	
		}	
		else
		cout<<"Yes"<<endl;
	}
	return 0;	
} 
