/*#include<iostream>//冰封王座 贪心算法 
using namespace std; 
int main() 
{  	
	int T;
	cin>>T; 
    while(T--) 
	{   
		int N,sum=0; 
	   	cin>>N;   
	   	if(N<150)   sum=N;  
	    if(N>=150&&N<200)   sum=N-150;   
		if(N>=200&&N<300)   sum=N-200;  
		if(N>=300)   sum=N%50;   
		cout<<sum<<endl;  
	}  
	return 0; 
}*/
#include <iostream>  //完全背包问题 
using namespace std;  
int main()  
{  
    int T;  
    int n;  
    int price[]={150,200,350};  
    int dp[10005]={0};  //初始化很重要 
    for(int i=0;i<2;i++)  
    {  
        for(int j=price[i];j<=10001;j++)  
        {  
            if(dp[j-price[i]]+price[i]>dp[j])  
                dp[j] = dp[j-price[i]]+price[i];  
        }  
    }
    while(cin>>T)  
    {  
    
        while(T--)  
        {  
            cin>>n; 
            cout<<n-dp[n]<<endl;  
        }  
    }  
    return 0;  
} 
