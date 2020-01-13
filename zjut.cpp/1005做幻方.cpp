#include <iostream>
#include<cstring>
#include <iomanip>
using namespace std;
int main()
{
 	int i,j,k,n;
	int a[31][31];
 	while(cin>>n,n)
 	{
   		memset(a,0,sizeof(a));
   		i=n-1;j=n/2;
   		a[i][j]=1;//先将最下面一行中间位置置1
   		for(k=2;k<=n*n;k++)
   		{
      		if(a[(i+1)%n][(j+1)%n]==0) 
   			{
			   	i=(i+1)%n;
				j=(j+1)%n;
			}
   			else 
				i=(i-1+n)%n;
   			a[i][j]=k; 
   		}
   		for(i=0;i<n;i++)
   		{
      		for(j=0;j<n;j++)
          	{
			  cout<<setw(3)<<a[i][j];
			}
          	cout<<endl;
   		}
   		cout<<endl;
 	}
    return 0;
}
