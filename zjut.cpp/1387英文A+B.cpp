#include<iostream>
#include<string>
using namespace std;//Ó¢ÎÄ°æA+B 
int f(string s)
{
	if(s=="zero")   return 0;
	else if(s=="one")return 1;
	else if(s=="two") return 2;
	else if(s=="three")return 3;
	else if(s=="four") return 4;
	else if(s=="five") return 5;
	else if(s=="six")  return 6;
	else if(s=="seven") return 7;
	else if(s=="eight") return 8;
	else if(s=="nine")   return 9;
	return 0;
}
int main()
{
	string s1,s2,s3,s4,s5,s6; 
	while(cin>>s1>>s2>>s3>>s4)
	{
		if(s1=="zero"&&s3=="zero"&&s4=="=")
		break;
		 if(s4=="=")
		{
			cout<<f(s1)+f(s3)<<endl;
			continue;
		}
		cin>>s5;
		 if(s5=="=")
		{
			if(s2=="+")
			{
				cout<<f(s1)+f(s3)*10+f(s4)<<endl;
				continue;
			}
			else
			{
				cout<<f(s1)*10+f(s2)+f(s4)<<endl;
				continue;
			}

				
		}
		cin>>s6;
		if(1)
		{		
			cout<<f(s1)*10+f(s2)+f(s4)*10+f(s5)<<endl;
			continue;
		}
		
	}
	return 0;
} 
