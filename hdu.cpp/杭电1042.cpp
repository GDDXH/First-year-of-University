#include <iostream>  
using namespace std;  
int main()  
{  
  int n;  
  while(cin>>n)  
  {  
      int a[50000]={0},i,j,digit=1;  
      a[0]=1;  
      for(i=2;i<=n;++i)  
      {  
        int count;  
        for(j=0,count=0;j<digit;++j)  
        {  
          int s=a[j]*i+count;  
          a[j]=s%10;  
          count=s/10;  
        }  
        while(count)  
        {  
          a[digit++]=count%10;  
          count/=10;  
        }  
      }  
      for(i=digit;i>=1;i--)  
      {  
        cout<<a[i-1];  
      }  
      cout<<endl;  
  }  
  return 0;  
}  
