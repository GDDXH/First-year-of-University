#include<iostream>
using namespace std;
const int maxn = 1000001;
int a[maxn]; 
int main()
{
	int n;
	a[0] = a[1] = 1;
	a[2] = a[3] = 2;
	for(int i=4;i<=1000000;i++)
	{
		if(i%2==1)
			a[i] = a[i-1];
		else
		{
			a[i] = a[i-2] + a[i/2];
			a[i] %=1000000000;
		}
	}
	while(cin>>n)
		cout<<a[n]<<endl;
	return 0;
 } 
