#include<iostream>
using namespace std;
int gcd(int a,int b)//Greatest common divisor 最大公约数 
{
	int t;
	if(a<b)
	{
	t=a;
	a=b;
	b=t;	
	}
	while(t=a%b)
	{
		a=b;
		b=t;
	}
	return b;
}
int main()
{
	int n1,n2,n3,Storage;
	cin>>n1;
	while(n1--)
	{
		cin>>n2;
		for(int i=1;i<=n2;i++)
		{
			cin>>n3;
			if(i==1) 
			{
				Storage=n3;
			}
			else
			Storage=Storage/gcd(Storage,n3)*n3;//注意 不能 Storage*n3，数据会超限 
		} 
		cout<<Storage<<endl;
	}
} 
