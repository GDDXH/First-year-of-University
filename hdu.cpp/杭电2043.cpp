#include<iostream>
#include<cstdio>
#include<cstdlib> 
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	int size,len,sum1,sum2,sum3,sum4,i;
	char a[100];
	cin>>size;
	while(size--)
	{	
		sum1=sum2=sum3=sum4=0;
		bool flag=false;
  		cin>>a;
  		len=strlen(a);
  		if(len>=8&&len<=16)
  		{
   			for(i=0;i<len;i++)
   			{
    			if(a[i]>='A'&&a[i]<='Z')
    				sum1=1;
    			else if(a[i]>='a'&&a[i]<='z')
    				sum2=1;
  			    else if(a[i]>='0'&&a[i]<='9')
   					sum3=1;
    			else
    				sum4=1;
   				 if(sum1+sum2+sum3+sum4>=3)
    			{
    				flag=true;
    				break;
    			}
   			}
  		}
  		if(flag)
  			cout<<"YES"<<endl;
 		else
 			cout<<"NO"<<endl;
	}
 	return 0;
}
