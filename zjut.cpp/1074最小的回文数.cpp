/*
解题思路是构造回文数： 
	取出前半截(包括中位数),
    从中间往两边找到第一个不相等(因为不是回文数，所以肯定能找到)的数，
	若前面的小于后面的，则按1处理（用前半截数值加1，之后再构造新的回文数）；
    若前面的大于后面的，则直接用前半截来构造回文数。
    找不到则为回文数 ，则用前半截数值加1，之后再构造新的回文数； 
*/
#include<iostream>
#include<string>
using namespace std;
int comp(string s);
int main()
{
	string s;
	while(cin>>s)
	{
		int len = s.size();
		int temp=0,flag = comp(s); 
		if(flag)
		{
			temp = 1;
			for(int i=len/2 -(len%2?0:1);i>=0;i--)
			{
				s[i] +=temp;
				if(s[i]>'9')
				{
					s[i] = '0';
				}
				else
				{
					temp = 0;		
					break;
				}
			}
		}
		if(temp)
			cout<<1<<string(len - 1,'0')<<1<<endl;
		else
		{
			for(int i=0;i<=len/2 -(len%2?0:1);i++)
				cout<<s[i];
			for(int i=len/2-1;i>=0;i--)
				cout<<s[i];	
			cout<<endl;
		}
	
	}
}
int comp(string s)
{
	int len = s.size();
	for(int i = len/2 -(len%2?0:1);i>=0;i--)
	{
		if(s[i]>s[len-i-1])
			return 0;
		if(s[i]<s[len-i-1])
			return 2;	
	}
	return 1;
 } 
