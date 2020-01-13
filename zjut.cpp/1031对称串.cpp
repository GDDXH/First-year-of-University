#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool judge(string s1)
{
	string s2=s1;
	reverse(s1.begin(),s1.end());
	if(s1==s2)
		return 1;
	return 0;
}
bool rule(string a,string b)
{
	return a.size()<b.size(); 
}
int main()
{
	string str;
	vector < string > array;
	while(cin>>str)
	{
		if(judge(str))
			array.push_back(str);
	}		
	sort(array.begin(),array.end(),rule);
	for(int i = 0 ; i<array.size() ;i++)
	{
		cout<<array[i]<<endl;
	}
}
