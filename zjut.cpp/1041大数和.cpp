#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
/*string big_number_add(string s,string result)
{
	int temp,i,ans=0;
	if(s.size()<result.size()){
		string t;
		t = s;
		s = result;
		result = t;
	}
	reverse(s.begin(),s.end());
	reverse(result.begin(),result.end());
	int len =result.size();
	for(i=0;i<len;i++)
	{
		temp = (s[i]-'0')+(result[i]-'0')+ans;
		ans = temp /10;
		s[i] = temp%10+'0';
	}
	while(ans>0)
	{
     
		if(i<s.size())
		{
			temp =s[i]-'0'+ ans;
		 	ans = temp/10;
			s[i] = temp%10+'0';
			i++;
		}
		else
		{
			s+=ans+'0';
			ans = 0;
		}
	}
	reverse(s.begin(),s.end());
	return s;
}*/
string big_number_add(string s,string result)
{
	string re="";
	s = string (max(s.size(),result.size())-s.size(),'0') + s;
	result = string (max(s.size(),result.size())-result.size(),'0') + result;
	int i ,temp ,ans=0;
	for(i=s.size()-1;i>=0;i--)	
	{
		temp = s[i] + result[i] -2*'0' + ans;
		ans = temp/10;
		re = char(temp%10 + '0') + re;
	}
	if(ans)
		re = char(ans+'0') + re;
	return re; 
}

int main()
{
	string s,result="0";
	while(cin>>s)
	{
		result = big_number_add(s,result);
	}
	cout<<result<<endl;
 } 
