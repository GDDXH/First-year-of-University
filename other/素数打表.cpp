#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>
using namespace std;
const long long int N = 10000000; 
int  *prime = new int [N];
bool visit[N];
void init_prime_1()  //ʱ�临�Ӷ�Ϊn^2��������� 
{  
	memset(prime,0,sizeof(prime));  
	int i, j;  
	for(i = 2;i <sqrt(N); i++){  
	    if(!prime[i])  
	        for(j = i*i;j < N;j += i) 
			//Ӧ����i*i��2*i��һ���ᱻ2�������ظ������� ,����i*i����������������Ӷ��������鳬���������ޣ�������� 
	        	prime[j]=1;  
	} 
	for(i = 2,j = 0;i < N; i++)       
	    if(!prime[i])   
	        prime[j++] = i;  
}
void init_prime_2() // ��Ϊ��Ч��������� 
{  
	//����������Ҫ���ʱ���ȹ��������ĸ���:num = n / lnx; 
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
			/*�㾦֮��,�˴����ص㣬�����˺ܶ���ظ��жϣ�
			����i=9,����������2,3,5,7,�������ѭ����visit[2*9]=1;visit[3*9]=1��
			���ʱ��9%3==0��Ҫ��������Ϊ5*9������3*15�����棬������ʱ������ˣ�
			i=15��ʱ���ֻᱻ�ظ�����һ�Σ�������������������ظ����㡣  */
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
