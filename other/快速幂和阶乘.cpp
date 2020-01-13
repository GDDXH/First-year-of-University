#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<iomanip> 
using namespace std;
const int mod = 9999991;
int OrdinaryPow(int m,int n);
int MyQuickPow(int m,int n);
int Factorial(int n);//阶乘 
int FactorialDigit(int n);//计算阶乘位数,可参考斯特林公式(stirling) 
int main()
{
	long long int m,n; 
	cout<<setw(50)<<"快速幂"<<endl
	
		<<"快速幂取模,快速的求一个幂式的模(余)。在程序设计过程中，经常要去求一些大数对于某个数的余数"<<endl 
		
		<<"为了得到更快、计算范围更大的算法，产生了快速幂取模算法。"<<endl; 
	
	cout<<"求m^n,请输入m,n"<<endl;
	cin>>m>>n;
	clock_t start = clock();
	cout<<OrdinaryPow(m,n)<<endl;
	clock_t finish = clock();
	cout<<finish-start<<"ms"<<endl;
	
	start = clock();
	cout<<MyQuickPow(m,n)<<endl; 
    finish = clock();
	cout<<finish-start<<"ms"<<endl;

	cout<<"阶乘"<<endl;
	cout<<"请输入n:";
	cin>>n;
	cout<<FactorialDigit(n)<<endl;
}
int OrdinaryPow(int m,int n)
{
	int result = 1;
	int base = m %mod;
	for(int i=0;i<n;i++)
	{
		result *= base;
		result %= mod;
	 } 
	 return result%mod;
} 
int MyQuickPow(int m,int n)
{
	long long int result = 1;
	long long int base = m%mod;
	while(n!=0)
	{
		if(n&1!=0)
			result =(result*base)%mod;
		base =(base*base)%mod;
		n >>=1;
	}
    return result%mod;
 } 
int OrdinaryFactorial(int n)
{
	long long int  result = 1;
	for(int i=1;i<=n;i++)
	{
		//cout<<result<<endl;
		result = result*i%mod;
	}
	return result;
}
int FactorialDigit(int n)
{
	long long int d;
	for(int i=1;i<=n;i++)  
	{
		d+=log10(i);  	
	}
    return d+1;
}
