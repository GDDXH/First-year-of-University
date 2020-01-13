#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	
		char a[100];
		cin>>a;
		int i;
		if(a[0]=='-')
		{
			cout<<a[0];
			for(i=strlen(a)-1;i>0;i--)
			{
				cout<<a[i];
			}
			cout<<endl;	
		}
		else
		{
			for(i=strlen(a)-1;i>=0;i--)
			{
					cout<<a[i];
			}
			cout<<endl;	
		}	
	}	
} 
