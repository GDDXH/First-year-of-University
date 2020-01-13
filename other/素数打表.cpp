#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>
using namespace std;
const long long int N = 10000000; 
int  *prime = new int [N];
bool visit[N];
void init_prime_1()  //时间复杂度为n^2的素数打表 
{  
	memset(prime,0,sizeof(prime));  
	int i, j;  
	for(i = 2;i <sqrt(N); i++){  
	    if(!prime[i])  
	        for(j = i*i;j < N;j += i) 
			//应该是i*i，2*i就一定会被2整除，重复计算了 ,但是i*i很容易数据溢出，从而导致数组超出索引界限，程序崩溃 
	        	prime[j]=1;  
	} 
	for(i = 2,j = 0;i < N; i++)       
	    if(!prime[i])   
	        prime[j++] = i;  
}
void init_prime_2() // 更为高效的素数打表 
{  
	//遇到素数需要打表时，先估算素数的个数:num = n / lnx; 
	memset(prime,0,sizeof(prime));
    memset(visit, true, sizeof(visit));  
    long long int i,j,num=0;
    for (i=2; i < N; i++){  
        if (visit[i] == true)  {  
            prime[num++] = i;  
        }  
        for (j = 0;(j<num)&&(i*prime[j]<N);j++)  
        {  
            visit[i * prime[j]] = false;  
            if (i % prime[j] == 0) 
				break; 
			/*点睛之笔,此处是重点，避免了很多的重复判断，
			比如i=9,现在素数是2,3,5,7,进入二重循环，visit[2*9]=1;visit[3*9]=1；
			这个时候9%3==0，要跳出。因为5*9可以用3*15来代替，如果这个时候计算了，
			i=15的时候又会被重复计算一次，所以这里大量避免了重复运算。  */
        }  
    }  
}  
int main() 
{	
	clock_t start = clock();
	init_prime_1();
	clock_t final = clock();
	cout<<prime[0]<<" "<<prime[1]<<" "<<prime[2]<<endl;
	/*
	cout<<(double)final-start<<"ms"<<endl;
	start = clock();
	init_prime_2();
	final = clock();
	cout<<(double)final-start<<"ms"<<endl;
	*/
}
