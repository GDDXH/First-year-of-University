#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	while(cin>>num)
	{
		int i,temp;
		double sum=0;
		int a[101];
		for(i=1;i<=num;i++)
		{
			cin>>temp;
			a[i]=temp;
		}
		sort(a+1,a+num+1);
		for(i=2;i<num;i++)
		{
			sum+=a[i];

		}
		cout.precision(2);
		cout<<fixed<<sum/(num-2)<<endl;	
	}
 } 
