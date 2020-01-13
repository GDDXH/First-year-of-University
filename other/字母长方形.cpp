/* 
Description
给定长和宽，请输出一个长方形，并a-z按顺序填充。
Input
多组数据，读到文件末
每组数据输入a，b代表宽和高,0<a,b<=20
Output
请输出以字符为填充的长方形，每个图案之间空一行*/ 
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
