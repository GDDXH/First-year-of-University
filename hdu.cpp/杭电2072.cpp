#include<iostream>
#include<string>
#include<set>
using namespace std;  
int main()  
{  
	string s;
	while(getline(cin,s),s!="#")
	{
		set <string> pack;
		string t;
		int len = s.size();
		for(int i=0;i<len;i++)
		{
			if(s[i]!=' ')
				t+=s[i];
			else
			{
				if(t!="")
					pack.insert(t);
				t="";
			}	
		} 
		if(t!="")
			pack.insert(t);
		int result = pack.size();
		pack.clear();
		cout<<result<<endl;
	}
	return 0;
} 
