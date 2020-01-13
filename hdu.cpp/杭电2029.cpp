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
	int size,i,len;
	string s;
	bool flag;
	cin>>size;
	while(size--)
	{
		flag=true;
		cin>>s;
		len=s.size(); 
		for(i=0;i<len/2;i++)
		{
			if(s[i]!=s[len-i-1])
			{
				flag=false;
				break;
			}
		 } 
		if(flag)
		 	cout<<"yes"<<endl;
		else
		 	cout<<"no"<<endl;
	}
}
