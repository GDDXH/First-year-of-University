#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool rule(const string &s1,const string &s2)
{
	if(s1.length()!=s2.length()) return s1.length()<s2.length();
	int c1=count(s1.begin(),s1.end(),'1');
	int c2=count(s2.begin(),s2.end(),'1');
	return (c1!=c2?	c1<c2:s1<s2);
}
int main()
{
	vector<string> ve;
	for(string s;cin>>s;)
	{
		ve.push_back(s);
	}
	sort(ve.begin(),ve.end(),rule);
	for(int i=0;i<ve.size();i++)
	{
		cout<<ve[i]<<endl;
	}
	return 0;
}
