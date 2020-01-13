/*1 题目意思很明确：　　　　　　　　　　　　　　　　　　
1　　 01　　　　　　　　　　　　　　　　　　　　0
2　　 1001　　　　　　　　　　　　　　　　　　　1
3　　 01101001　　　　　　　　　　　　　　　　　1
4　　 1001011001101001　　　　　　　　　　      3
5　　 01101001100101101001011001101001　　　　　5
通过自己推算，我们可以发现规律：从4开始，第n串中00的来源主要有两部分：
1. 第n-2串中00的数目
2. 第n-2串中1的数目而第n串中1的数目=2^(n-1)
因此，递推公式为：
C(n)=C(n-2)+2^(n-3) 其中n>=4。*/
#include<iostream>
using namespace std;
const int MAX=1000;
const int size=400;
int n[MAX][size]={{0},{0},{1},{1}}; //前四项初始化
int b[MAX]={1};
void table()
{
	int i,j,k,z;
	for(i=4;i<=12;i++)
	{
		for(j=0,k=0,z=0;j<size;j++)
		{
			b[j]=2*b[j]+k;          //数组b存取2^n，降位存取。
			k=b[j]/10;         
			b[j]=b[j]%10;
			n[i][j]=b[j]+n[i-2][j]+z;//数组n存取连续字段0的个数,降位存取。
			z=n[i][j]/10;
			n[i][j]=n[i][j]%10;
		}
	}
}
int main()
{
	int i,N,flag;
	table();
	while(cin>>N)
	{	
		flag=0;
		if(N==1)
			cout<<"0";
		else if	(N==2 ||N==3)
			cout<<"1";
		else
			for(i=size-1;i>=0;i--)
			{
				if(n[N][i] || flag)
				{
					cout<<n[N][i];
					flag=1;
				}
			}
		cout<<endl;
	}
	return 0;
}
