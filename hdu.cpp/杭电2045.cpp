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
	long long int  a[51];  
    int i,t;  
    a[1]=3;  
    a[2]=6;  
    a[3]=6; 
    for(i=4;i<=50;i++)  
    {  
        a[i]=a[i-1]+2*a[i-2];  
    } 
    while(~scanf("%d",&t))  
    {  
        printf("%lld\n",a[t]);  
    }  
    return 0;
}
