#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	string s;
	int i,result,size;
	cin>>size;
	while(size--)
	{
		result=0;
		cin>>s;
		for(i=0;i<s.size();i++)
		{
			if(s[i]>=48&&s[i]<=58)
			{
				result++;
			}
		}
		cout<<result<<endl;
	}
	return 0;
}
