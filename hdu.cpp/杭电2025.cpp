#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int temp,len,i;
    char a[100];
    while(cin.getline(a,100,'\n'))
    {
        len=strlen(a); 
        temp=a[0];
        for(i=0;i<len;i++)
        {
            if(temp<a[i])
                temp=a[i];
        }
        for(i=0;i<len;i++)
        {
            printf("%c",a[i]);
            if(a[i]==temp)
                printf("(max)");
        }
        printf("\n");
    }
    return 0; 
}
