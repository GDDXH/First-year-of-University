/* 
Description
�������Ϳ������һ�������Σ���a-z��˳����䡣
Input
�������ݣ������ļ�ĩ
ÿ����������a��b�����͸�,0<a,b<=20
Output
��������ַ�Ϊ���ĳ����Σ�ÿ��ͼ��֮���һ��*/ 
#include<iostream>
using namespace std;
int main()
{
	int i,j,a,b,flag=false;
	char ch[30];
	for(i=0;i<26;i++)
		ch[i]='a'+i;
	while(cin>>a>>b)
	{
		if(flag)
			cout<<endl;
		flag = true;
		for(i=0;i<b;i++)
		{	
			for(j=0;j<a;j++)
			cout<<ch[(a*i+j)%26];
			cout<<endl;
		}
	}
 } 
