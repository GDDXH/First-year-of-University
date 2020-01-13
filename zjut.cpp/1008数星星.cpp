#include<iostream>  
#include<string>  
using namespace std;  
int main()  
{  
    string s;  
    int m,n;
 	while(cin>>m>>n)
    {  
        if(m==0||n==0)break;  
        int sum=0;  
        while(m--)  
        {  
            cin>>s;  
            for(int i=0;i<n;i++)  
            {  
                if(s[i]=='*')sum++;  
            }  
        }  
        cout<<sum<<endl;  
    }     
}  
