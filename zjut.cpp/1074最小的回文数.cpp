/*
����˼·�ǹ���������� 
	ȡ��ǰ���(������λ��),
    ���м��������ҵ���һ�������(��Ϊ���ǻ����������Կ϶����ҵ�)������
	��ǰ���С�ں���ģ���1������ǰ�����ֵ��1��֮���ٹ����µĻ���������
    ��ǰ��Ĵ��ں���ģ���ֱ����ǰ����������������
    �Ҳ�����Ϊ������ ������ǰ�����ֵ��1��֮���ٹ����µĻ������� 
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
