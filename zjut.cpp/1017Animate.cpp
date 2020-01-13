#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int flag=0;
		string s1,s2;
		while(getline(cin,s1)&&s1!="#End")
		{
			
			for(int i=0;i<s1.length();i++)
			{
				if(s1[i]>='A'&&s1[i]<='Z')
					s1[i]+=32;
				if(s1[i]>='a'&&s1[i]<='z')
					s2+=s1[i];
			}
			if(s2.find("animate")!=string::npos)
				flag=1;
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
} 
