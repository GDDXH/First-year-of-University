#include<iostream>
using namespace std;
int main()
{
	int x1,y1;//��һ��������Ϊ�������ĵ�
	int x2,y2;//��¼����ĵ� 
	int m,n;//���������ĵ�
	long long int distance=2147483647; 
	cin>>x1>>y1;
	while(cin>>m>>n)
	{
		
		long long int sum=(x1-m)*(x1-m)+(y1-n)*(y1-n);//�ǳ����׳���int��Χ 
		if(distance>sum)
		{
			distance=sum;
			x2=m;
			y2=n; 
		}
	}
	cout<<x2<<" "<<y2<<endl;
}
