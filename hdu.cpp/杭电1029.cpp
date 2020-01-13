#include<iostream>//关键是sort函数的运用 
#include <algorithm>
using namespace std;
int a[1000000];
int main()
{
	int t;
	while(cin>>t)
	{		
		for(int i=0;i<t;i++)
			{
			cin>>a[i];
			}
			sort(a,a+t);
			cout<<(a[(t+1)/2])<<endl;
	}
	return 0; 
 } 
