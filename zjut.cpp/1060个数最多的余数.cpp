#include<iostream>
using namespace std;
int main()
{
	int a[100]={0};
	int n,max=0;
	while(cin>>n)
	{
		a[n%100]++;
	}
	for(int i=0;i<100;i++)
	{
		if(a[max]<a[i])
			max = i;
	}
	cout<<max<<endl; 
 } 
