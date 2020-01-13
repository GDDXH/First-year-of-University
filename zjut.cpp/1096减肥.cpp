#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n1;
	cin>>n1;
	while(n1--)
	{
		int n2;
		int a[51],b[51],c[51];
		cin>>n2;
		for(int i=1;i<=n2;i++)
		{
			cin>>a[i]>>b[i];
			c[i]=b[i]-a[i];
		}
		sort(c+1,c+n2+1);
		for(int i=1;i<=n2;i++)
		{
			cout<<c[i];
			if(i!=n2)
			cout<<" "; 
		}
		cout<<endl;
	}
 } 
