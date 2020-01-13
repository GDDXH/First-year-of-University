#include<iostream>
using namespace std;
int leijia (int x) 
{  
    int j=1;  
    for(int i=x;i>=1;i--)  
    {  
        j*=i;  
    }  
    return j;  
}  
int main()
{
	int i,j;
	cout<<"n"<<" "<<"e"<<endl;
	cout<<"- -----------"<<endl;
	for( i=0;i<=9;i++)
	{
		cout.precision(9);
		double k=1;
		if(i==0)
		{
			cout<<i<<" "<<k<<endl;
		} 
		if(i==1)
		{
			k=2;
			cout<<i<<" "<<k<<endl;
		} 
		if(i==2)
		{
			k=2.5;
			cout<<i<<" "<<k<<endl;
		} 
		if(i>2)
		{
			for(j=1;j<=i;j++)
			{
				k+=1.0/leijia(j);
			}
		cout<<fixed<<i<<" "<<k<<endl;		
		}


	}
}
