//判断回文，1：左边与右边一一配对  2:将s1字符串反转得s2 s1==s1?true:false  
#include<iostream>
#include<string>
using namespace std;
int main() 
{
	string s;
	while(getline(cin,s))
	{
		if(s=="000000") 
			break; 
		int len = s.size();
		bool flag = true;
		
		for(int i=0;i<len/2;i++)
		{
			if(isalpha(s[i])){
				s[i] = tolower(s[i]);
				s[len-i-1] = tolower(s[len-i-1]); 
				if(s[i]==s[len-i-1])
					continue;
				else{
					flag =false;
					break;	
				}
				
			}
			if(s[i]=='[') 
			{
				if(s[len-i-1]!=']'){
					flag = 0; 
					break;
				}
			}
			else if(s[i]=='{')
			{
				if(s[len-i-1]!='}'){
					flag = 0; 
					break;
				}
				
			}
			else if(s[i]=='<') 
			{
				if(s[len-i-1]!='>'){
					flag = 0; 
					break;
				}
			}
			else if(s[i]=='(') 
			{
				if(s[len-i-1]!=')'){
					flag = 0; 
					break;
				}
			}
			else
			{
				if(s[i]!=s[len-i-1]){
					flag = 0; 
					break;
				}
			}
		}
		if(flag)
			cout<<"Symmetry"<<endl;
		else
			cout<<"Not symmetry"<<endl;
	}
	return 0;
}
