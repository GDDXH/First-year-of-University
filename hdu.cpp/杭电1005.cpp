#include<iostream>
using namespace std;
int n[50];
int main()
{
	int a,b,t;
	while(cin>>a>>b>>t&&t!=0)
	{
		n[1]=1;
		n[2]=1;
		for(int i=3;i<=50;i++)
		{
			if(i<=50)n[i]=(a*n[i-1]+b*n[i-2])%7;		
		}
		cout<<n[t%48]<<endl;
	}
	return 0;	
 } 

