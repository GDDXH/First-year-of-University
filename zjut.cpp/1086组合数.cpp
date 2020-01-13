#include<iostream>
using namespace std;
int main()
{
	int m,n,t;
	while(cin>>m>>n)
	{
		long long int num= 1;
		if(m/2<n)	n=m-n;
		for(int i = m,j=1;j<=n;i--,j++)
			num = num*i/j;
		cout<<num<<endl;	
	}
 } 
