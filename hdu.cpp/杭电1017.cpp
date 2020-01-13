#include<iostream>
using namespace std;
int main()
{
	int n,m,t,counter_1=0,counter_2=1;;
	cin>>t;
	while(t--)
	{
		while(cin>>n>>m&&n!=0) 
		{
			for(int a=1;a<n;a++)
			{
				for(int b=a+1;b<n;b++)
				{
					if((a*a+b*b+m)%(a*b)==0)
					{
						counter_1++;
					}
				}
			}
			cout<<"Case "<<counter_2++<<": "<<counter_1<<endl;
			counter_1=0;				
		}
		counter_2=1;  
    	if(t)  
    	cout<<endl;  		
	} 
	return 0;
} 
  
