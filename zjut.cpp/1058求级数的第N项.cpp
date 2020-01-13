#include<iostream>  
using namespace std;  
int main()  
{  
  	int i,a[17];
  	a[1]=0;
  	a[2]=2;
  	for(i=3;i<17;i++)
  	{
  		a[i]=3*a[i-1]+5*a[i-2];
  	}
  	int num;
  	while(cin>>num)
  	{
  		if(num==0)	break;
  		cout<<a[num]<<endl;
  	}
}  
