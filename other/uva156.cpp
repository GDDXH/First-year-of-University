#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cctype>
#include<set>
#include<map>
using namespace std;
int main()
{
	set<string>result;
	map<string,int> temp;
	string s,record_front[1010],record_behind[1010];
	int i,len,k=0;
	while(cin>>s)
	{
		if(s=="#")
			break;
			
		record_front[k]=s;
		
		for(i=0,len=s.length();i<len;i++)
		{
			s[i]=tolower(s[i]);
		}
		sort(s.begin(),s.end());
		record_behind[k++]=s;
		temp[s]++;	
	}	
	for(i=0;i<k;i++)
	{
		if(temp[record_behind[i]]==1)
			result.insert(record_front[i]);
	}
	for(set<string>::iterator it=result.begin();it!=result.end();it++)
	{
		cout<<*it<<endl;
	}
}
/*struct ss
{
	string a,b;
	bool c;
};
bool rule(ss x,ss y)
{
	return x.a<y.a;
}
int main()
{
	int i,k=0;
	string s1,s2;
	ss s[1010];
	bool flag;
	while(cin>>s1)
	{
		if(s1=="#")
			break;
		flag=true;
		s2=s1;
		int len=s1.size();
		for(i=0;i<len;i++)
		{
			s1[i]=tolower(s1[i]);	
		}
		sort(s1.begin(),s1.end());
		for(i=0;i<k;i++)
		{
			if(s1==s[i].b)
			{
				flag=false;
				s[i].c=false;
				break;
			}
		}
		if(flag)
		{
			s[k].a=s2;
			s[k].b=s1;
			s[k].c=true;
			k++;
		}
	}
	sort(s,s+k,rule);
	for(i=0;i<k;i++)
	{
		if(s[i].c==true)
		cout<<s[i].a<<endl;
	}
} */
