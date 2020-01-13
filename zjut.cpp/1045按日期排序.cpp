#include<iostream>
#include<algorithm> 
#include<vector>
#include<string> 
using namespace std;
bool rule(string a,string b);
int main()
{
	string s;
	vector<string>array;
	while(cin>>s)
	{
		array.push_back(s);
	}
	sort(array.begin(),array.end(),rule);
	for(int i=0,len=array.size();i<len;i++)
	{
		cout<<array[i]<<endl;
	 } 
	return 0;
}
bool rule(string a,string b)
{
	a = a.substr(6,4)+a.substr(0,5);
	b = b.substr(6,4)+b.substr(0,5);
	return a<b;
}

