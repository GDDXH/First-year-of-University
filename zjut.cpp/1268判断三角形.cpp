#include<iostream>
using namespace std;
bool judge(int a,int b,int c)
{
	if(a>=b+c)
	return false;
	else if (b>=a+c)
	return false;
	else if (c>=a+b)
	return false;
	else return true;	
} 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(judge(a,b,c))cout<<"YES"<<endl;
		else cout<<"NO"<<endl; 
	}	
} 
