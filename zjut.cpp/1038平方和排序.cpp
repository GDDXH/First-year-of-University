#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
bool comp(string a,string b)
{
	int sum_a=0,sum_b=0;
	for(int i=0;i<a.size();i++)
		sum_a+=(a[i]-'0')*(a[i]-'0');
	for(int i=0;i<b.size();i++)
		sum_b+=(b[i]-'0')*(b[i]-'0');
	return sum_a<sum_b;

}
int main()
{
	int n;
	while(cin>>n,n)
	{
		string s;
		vector<string>arr;
		arr.clear(); 
		for(int i=0;i<n;i++)
		{
			cin>>s;
			arr.push_back(s);
		}
		sort(arr.begin(),arr.end(),comp);
		cout<<arr[0];
		for(int i=1;i<n;i++)
			cout<<" "<<arr[i];
		cout<<endl; 
	}
	return 0;
 } 
