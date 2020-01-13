//集合的差运算 
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
	int m,n,i,j,t,a[100],b[100],c[100];
	while(cin>>m>>n)
	{
		memset(c,1,sizeof(c)); 
		int flag=0;
		if(m==0&&n==0)
		{
			break;
		}
		for(i=0;i<m;i++)
		{
			cin>>a[i];
		}
		sort(a,a+m);
	 	for(i=0;i<n;i++)
		{  
            cin>>b[i];  
            for(j=0;j<m;j++)
			{  
                if(a[j]==b[i])  
                    c[j]=0;  
            }  
        }  
        for(i=0;i<m;i++)  
        {  
            if(c[i])
			{  
                if(flag>=1)cout<<" ";  
                cout<<a[i];   
                flag++;
            }  
        }  
        if(flag==0)cout<<"NULL"<<endl;  
        else cout<<" "<<endl;  
	} 
	return 0; 
}
