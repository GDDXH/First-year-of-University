#include<iostream>
using namespace std;
int main()
{
	int num;
	while(cin>>num)
	{	
		int i,j,t;
		for(i=1;i<=num;i++)
		{
			char c='a';
			cout<<c;
			t=num-i;
			while(t--)
			{
				cout<<" ";
			}
			for(j=1;j<=i;j++)
			{
				cout<<c;
				c=c+1;
			}
			cout<<endl;
		}
		cout<<endl;
	}
}
