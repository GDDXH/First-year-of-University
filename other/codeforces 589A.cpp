#include<iostream>
#include<map>
#include<vector> 
#include<string>
#include<cstring>
using namespace std;
map<string,int>mailbox;
vector<string>container[20010];
int main()
{
	int i,n,sign,id=0;
	char s[110],restore_s[110];
	scanf("%d",&n);
	while(n--) 
	{
		scanf("%s",s);
		strcpy(restore_s,s);
		for(i=0;s[i];i++)
		{
			s[i] = tolower(s[i]);
			if(s[i]=='@')
				sign = i;
		}
		if(!strcmp(s+sign+1,"bmail.com"))
		{
			int len = 0;
			for(i=0;i<sign;i++)
			{	
				if(s[i]=='.')	continue;
				if(s[i]=='+')	break;
				s[len++] = s[i];
			}
			for(i=sign;s[i];i++)
            {
                s[len++] = s[i]; 
            }
            s[len] = 0;
		}
		if(mailbox.find(s)==mailbox.end())
			mailbox[s]=id++;
		container[mailbox[s]].push_back(restore_s);
	}
	cout<<id<<endl;
	for(i=0;i<id;i++)
	{
		cout<<container[i].size();
		for(int j=0;j<container[i].size();j++)
		{
			cout<<" "<<container[i][j];
		}
		cout<<endl;
	}
	return 0;
 } 
