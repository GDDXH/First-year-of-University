//һ������N��M�η�֮���ĩλ����
//��Ҫʹ�ÿ����ݣ�����ʱ
//Ҳ����ʹ����ѧ���ɣ�һ�����ģ�4n+1���η�֮��ĩβ�ͳ�ʼ��ͬ 
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int fun(int x,int y)  
{  
 	int t=1;  
    x%=10;  
    while(y>0)  
    {  
        if(y&1)  
        	t=t*x%10;   
        x=x*x%10;  
        y/=2;  
    }  
    return t;  
} 
int main()
{
	int i,a,b,result;
	while(~scanf("%d %d",&a,&b))
	{
		printf("%d\n",fun(a,b));  
	}
	return 0;
}
