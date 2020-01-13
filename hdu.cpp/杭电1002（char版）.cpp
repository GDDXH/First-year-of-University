#include<iostream>  
#include<cstring>  
#define MAX 1001 
using namespace std;  
int main()
{  
    int i,j,T,counter=1;  
    cin>>T;  //T组数据 
    char a[MAX],b[MAX];  
  	int  a1[MAX],b1[MAX];   
    while(T--)
		{   
    	cin>>a>>b;  
   		int a_length=strlen(a);  
    	int b_length=strlen(b);  
    	for(i=0;i<MAX;i++)
			{  
        	a1[i]=0;  
        	b1[i]=0;  
    		}  
    	for(i=0;i<a_length;i++) 
			{   
       	 	a1[i]=a[a_length-1-i]-48;  
        	} 
    	for(i=0;i<b_length;i++)    
			{
			b1[i]=b[b_length-1-i]-48;
			}	   
    	int n=0;    //进位 
   	 	for(i=0;i<MAX;++i)
			{  
        	int s=a1[i]+b1[i]+n;  
       	 	a1[i]=s%10;  
        	n=s/10;  
   			}         
        cout<<"Case "<<counter++<<":"<<endl;   
        for(i=0;i<a_length;++i)  
          cout<<a[i];  
        cout<<" + ";  
        for(i=0;i<b_length;i++)  
          cout<<b[i];  
        cout<<" = ";    
        for(i=MAX-1;i>=0;--i)
			 if(a1[i])break;  
        for(j=i;j>=0;j--)
			{  
        cout<<a1[j];      
      		}  
       		cout<<endl;  
       		if(T) cout<<endl;  
    	}  
      
}  
  
  
