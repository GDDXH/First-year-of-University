#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double sum=0;
	int i=0;
	int n;
	while(cin>>n)
	{
		sum+=n;
		i++;
	}
	cout<<setprecision(2)<<fixed<<sum/i<<endl;
 } 
 	/*int n, a, sum;
	n = sum = 0;
	while (scanf("%d", &a) != EOF)
	{
		n++;
		sum += a;
	}
	printf("%.2f\n", 1.0*sum/n);*/
	//学长用C语言，1.0*sum/n是亮点，需学习 
