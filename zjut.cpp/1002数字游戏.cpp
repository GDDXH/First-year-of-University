#include<iostream>  
#include<cmath>  
using namespace std;  
int main()
{  
    double n;  
    while(cin>>n,n)//µÈ¼ÛÓÚ cin>>n&&n 
	{  
        if(n==1)
		{
			cout<<"0 0"<<endl;
			continue;
		}  
        int flag=1;  
        for(int i=2;i<=7;i++)
		{  
            double m=n;  
            double k = ceil(pow(m,1.0/i));  
            if(pow(k,i*1.0)==m)
			{  
                flag=0; 
                cout<<k<<" "<<i<<endl;
				break;  
            }  
        }  
        if(flag) 	cout<<"0 0"<<endl;
    }  
}
