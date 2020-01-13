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
	int size,i;
	cin>>size;
	getline(cin,s);
	while(size--)
	{
		getline(cin,s);
		if(s[0]=='_'||(s[0]>='A' && s[0]<='Z') || (s[0]>='a' && s[0]<='z'))
  		{
  		 	for(i=1;i<s.length();i++)
   			{
   		 		if((s[i]=='_' )||(s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') ||(s[i]>='0' && s[i]<='9'))
     				continue;
    			else
     				break;
  			 }
  			  
  			 if(i==s.length())
   				cout<<"yes"<<endl;
   			else
    			cout<<"no"<<endl;
 		}
 		else
   			cout<<"no"<<endl;
  	}
	return 0;		
}
