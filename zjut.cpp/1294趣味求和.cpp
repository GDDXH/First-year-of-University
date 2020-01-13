#include<iostream>
#include<cmath> 
using namespace std;
int main()
{
	int a,n;
	while(cin>>a>>n)
	{
		int i,sum=0;
		for(i=0;i<n;i++)
		{
			sum+=a*(n-i)*pow(10,i*1.0);
		}
		cout<<sum<<endl;
	}
}
