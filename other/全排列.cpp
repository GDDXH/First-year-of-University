#include<iostream>//不如直接使用next_permutation 
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
vector<string> result;
int ans=0;

void permutation(string s,int k,int m)
{
	if(k==m)
	{
		result.push_back(s);
	}
	else
	{
		for(int i=k;i<=m;i++)
		{
			swap(s[i],s[k]);
			permutation(s,k+1,m);
			swap(s[i],s[k]);
		}
	}
}

int main()
{
	int n;
	while(cin>>n)
	{
		string s;
		result.clear();
		for(int i=0;i<n;i++)
			s+=i+'1';
		permutation(s,0,n-1);
		sort(result.begin(),result.end());
		int len = result.size();
		for(int i=0;i<len;i++)
		{
			cout<<result[i][0];
			for(int j=1;j<n;j++)
			cout<<" "<<result[i][j];
			cout<<endl;
		}
	}
	return 0;
} 
