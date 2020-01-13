#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool rule(string a,string b)
{
	if(a.size()!=b.size())
		return a.size()<b.size();
	return a<b;
}
int main()
{
	int i,n,count=0;
	string s;
	vector< string > array;
	while(cin>>n&&n)
	{
		
		if(count)
			cout<<endl;
		count++;
		array.clear();
		for(i=0;i<n;i++)
		{
			cin>>s;
			array.push_back(s);
		}
		sort(array.begin(),array.end(),rule);
		for(i=0;i<n;i++)
		{
			cout<<array[i]<<endl;
		}
	}
}
 
