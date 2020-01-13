#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool rule(const string &s1,const string &s2)
{

	int size1=count(s1.begin(),s1.end(),'1');
	int size2=count(s2.begin(),s2.end(),'1');
	return size1<size2;
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
