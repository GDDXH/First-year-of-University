#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
	string s;
	int array[1001];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			array[i]=s[i]-'A'-13;
		}
		for(int i=1;i<s.length();i++)
		{
			if(array[i-1]>0)
			{
				array[i]+=array[i-1];
			}
		}
		int result=array[0];
		for(int i=0;i<s.size();i++)
		{
			result=max(array[i],result); 
		}
		printf("%d\n",result);
	}
	return 0;
 } 
