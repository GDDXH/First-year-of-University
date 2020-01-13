#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,sum;
		cin>>a>>b;
		sum=(a%100+b%100)%100;
		cout<<sum<<endl;
	}
}
