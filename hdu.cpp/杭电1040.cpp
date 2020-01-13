#include<iostream>//ºÚµ•µƒ≈≈–Ú£®sort”Î√∞≈›≈≈–Ú£© 
#include<algorithm>
using namespace std;
int main()
{
	int n1;
	cin>>n1;
	while(n1--)
	{
		int n2,n3;
		int a[1001];
		cin>>n2;
		for(int i=0;i<n2;i++)
		{
			cin>>n3;
			a[i]=n3;
		}
		sort(a,a+n2);
		for(int i=0;i<n2;i++)
		{
			cout<<a[i];
			if(i<n2-1)
			cout<<" ";
		}
		cout<<endl;
	}
 } 
