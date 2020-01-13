#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
#include<cctype>
#include<sstream>
using namespace std;
set<string> s;
int main()
{
	
	
	/*
	string s1;
	while(getline(cin,s1))
	{
		for(int i=0;i<s1.size();i++)
		{
			string s2;//相当于在循环外声明s2,再在循环中令s2="" 
			if(!isalpha(s1[i])) continue;
			while(isalpha(s1[i]))
			{
				s1[i]=tolower(s1[i]);
				s2+=s1[i];
				i++;
			}
			s.insert(s2);
		}
	} 
	for(set<string>::iterator it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<endl;
	}*/
  	string s1,s2;
  	stringstream ss;
  	while(cin>>s1)
  	{	
  
   		int len = s1.size(); 
   		for(int i=0;i<len;i++)
   		{
   			if(isalpha(s1[i]))
			   	s1[i]=tolower(s1[i]); 
			else
				s1[i]=' ';
		}
		ss<<s1;
		while(ss>>s2)
		{
			s.insert(s2); 	
		}
		//ss.clear();
		ss.str("");//清空stringstream,相当于在while中声明stringstream 
	} 
	for(set<string>::iterator it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<endl;
	}
   /*
    string s1,s2;
	while(cin>>s1)
   {
   		s2="";
   		for(int i=0;i<s1.size();i++)
   		{	
   			if(isalpha(s1[i]))
   			{
   				s1[i]=tolower(s1[i]);	
   				s2+=s1[i];
			}
		}
   		s.insert(s2);	
	} 
	for(set<string>::iterator it = s.begin();it!=s.end();it++)
	cout<<*it<<endl;
	*/
	return 0;
}
