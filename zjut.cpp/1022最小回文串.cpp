#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{	
	int num[26];
	int T;
	string s;
	cin>>T;
	while(T--)
	{
		int i,flag=-1;
		memset(num,0,sizeof(num));
		cin>>s;
		for(i=0;i<s.size();i++)
		{
			num[s[i]-'A']++;
		}
		for(i=0;i<26;i++)
		{
			if(num[i]%2!=0)
			{
				if(flag==-1)
					flag=i;
				else
					break;	
			}	
		}
		if(i!=26)
		{
			cout<<"Sorry"<<endl;
			continue;
		}
		for(i=0;i<26;i++)
		{
			cout<<string(num[i]/2,'A'+i);
		}
		if(flag!=-1)
			cout<<char('A'+flag);
		for(i=25;i>=0;i--)
		{
			cout<<string(num[i]/2,'A'+i);
		}
		cout<<endl;
	}
	return 0;
}
