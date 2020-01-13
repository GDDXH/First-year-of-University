#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int x,temp,add_flag; 
	while(cin>>s>>x)
	{
		if(s=="0"||x==0){
			cout<<"0"<<endl;
			continue;
		}
		int len = s.size();
		add_flag=0;
		for(int i=len-1;i>=0;i--)
		{
			temp = (s[i]-'0')*x+add_flag;
			add_flag = temp /10;
			s[i] = temp%10+'0';
		} 
		if(add_flag)
			s= char(add_flag+'0')+s;
		cout<<s<<endl;
	}
}
