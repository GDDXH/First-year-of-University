#include<iostream>
#include<cstdio> 
#include<cstring>
using namespace std;
void add(char a[],char b[],char c[])
{
	int i,j,k;
	char temp;
	int a_length=strlen(a);
	int b_length=strlen(b);
 	for(i=0; i<a_length/2; i++)
	{  
    	temp=a[i];  
        a[i]=a[a_length-1-i];  
        a[a_length-1-i]=temp;  
    }  
    for(i=0; i<b_length/2; i++)
	{  
        temp=b[i];  
        b[i]=b[b_length-1-i];  
        b[b_length-1-i]=temp;  
    }  
    j=0;
	for(i=0;i<a_length&&i<b_length;i++)
	{
		k=a[i]-'0'+b[i]-'0'+j;
		j=k/10;
		c[i]=k%10+'0';
	}
	if(i<b_length)
	{
		for(;i<b_length;i++)
		{  
            k=b[i]-'0'+j;  
            j=k/10;  
            c[i]=k%10+'0';  
        }  
	}	
	else
	{
		for(;i<a_length;i++)
		{  
            k=a[i]-'0'+j;  
            j=k/10;  
            c[i]=k%10+'0';  
        }  
	}
	if(j) c[i++]=j+'0';
	c[i]=0;
	int c_length=strlen(c);
	for(i=0; i<c_length/2 ;i++)
	{
		temp=c[i];
		c[i]=c[c_length-1-i];
		c[c_length-1-i]=temp;
	}
}
int main()
{
	char temp[110] ,sum[110];
	int t;
	scanf("%d",&t);
	getchar();  
	while(t--)
	{
		strcpy(sum,"0"); 
		while(1)
		{  
            scanf("%s",temp);  
            if(!strcmp(temp,"0"))
			break;  
            add(temp,sum,sum);  
        }  
		printf("%s\n",sum);  
        if(t) printf("\n");  
	}
	return 0;
} 
