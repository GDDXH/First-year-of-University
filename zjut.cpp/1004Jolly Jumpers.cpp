#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int data[3001];
		int difference[3001]={0};
		int sum=0;  
		for(int i=0;i<n;i++)
		{
			cin>>data[i];
		}
		for(int i=1;i<n;i++)  
        {
           	difference[abs(data[i]-data[i-1])]=1;   	
		}	
    
        for(int i=1;i<n;++i)
		{
		    sum+=difference[i];  
		}        
        if(sum==n-1)cout<<"Jolly\n";  
        else cout<<"Not jolly\n";  
	}
}
