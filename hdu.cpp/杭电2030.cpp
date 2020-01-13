#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	int n;  
    scanf("%d", &n);  
    getchar();  // ‰»Îªÿ≥µº¸ 
    while (n--)  
    {  
        char s[1000];  
        gets(s);  
        int sum=0;  
        for(int i=0;s[i]!='\0';i++)  
        {  
            if(s[i]<0) 
				sum++;  
        }  
        cout <<sum/2<<endl;  
    }  
    return 0;  
}
