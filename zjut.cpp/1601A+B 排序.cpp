#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int i=0;
	int j;
	int a,b;
	int sum[101];
	while(cin>>a>>b)
 	{
 		sum[i]=a+b;
 		i++;
 	} 
 	sort(sum,sum+i);
 	for(j=0;j<i;j++)
 	{
 		cout<<sum[j]<<endl;
	}
}
