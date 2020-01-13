#include<iostream>
#include<string>   
using namespace std;  
int main()  
{  
   	int i,j,n;  
	cin>>n; 
   	while(n!=0)  
    {  
    	string str[1001],color; 
		int num[1001]={0};   
   		for(i=0;i<1001;i++)  
    	str[i]=" ";  
       for(i=1;i<=n;i++)  
        {  
            cin>>color;  
           	for(j=1;j<i;j++)  
            {  
               	if(str[j]==color)  
            	{  
                   	num[j]++;  
                  	break;  
                }  
  
            }  
           if(i==j)  
            {  
            	str[i]=color;  
            	num[i]++;  
            }  
             
       }  
    	int max=0;  
		for(i=1;i<=n;i++)  
  		{  
   			if(num[i]>num[max])  
     		{  
     		max=i;   
    		}   
  		}  
		cout<<str[max]<<endl;   
  		cin>>n;    
    }   
	return 0;   
}  
