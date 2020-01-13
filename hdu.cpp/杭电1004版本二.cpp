#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n,i,k;
	string a[1002],b[1002];
	while(cin>>n&&n!=0)
	{
	int c[1001]={0};
	int p=0;
	k=0;
	for(i=0;i<n;i++)
		{
			cin>>a[i];
		} 
	b[0]=a[0];
	c[0]=1;
	for(i=1;i<n;i++)
		{
		if(b[k]!=a[i])
			{
				b[++k]=a[i];c[k]++;
			}
		else c[k]++;
		} 
	for(i=0;i<=k;i++)
		{
		if(c[i]>c[p]) 
			{
			p=i;
			} 
		} 
	cout<<b[p]<<endl;
	}
return 0;
}
