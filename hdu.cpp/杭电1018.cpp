#include<iostream>
#include<cmath>
using namespace std;
int main()
{
 	int num,t;
 	double digit;
 	cin>>t;
 	for(int i=0;i<t;i++)
 	{
  		cin>>num;
  		digit=0;
  		for(double j=1;j<=num;j++)
		{
			digit+=log10(j);  
		} 
  		cout<<(int)digit+1<<endl;
 	}
 	return 0;
}
