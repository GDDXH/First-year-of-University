#include<iostream>
using namespace std;
int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		int t,temp,temp_m,temp_n;
		if(m<n)
		{
			temp=m;
			m=n;
			n=temp;
		}
		temp_m=m;
		temp_n=n;
		while(t=temp_m%temp_n)
		{
			temp_m=temp_n;
			temp_n=t;
		}
		cout<<m/temp_n*n<<endl; 	//m*nÈÝÒ×³¬¹ýint·¶Î§ 
	}
 } 
