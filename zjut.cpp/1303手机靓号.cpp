#include<iostream>
using namespace std;
int main()
{
	char a[11];
	int count1=0;
	while(cin>>a)
	{
		int count2=0;
		for(int i=0;i<11;i++)
		{
		
			if(a[i]=='6'||a[i]=='8')
			{
				count2++;
			}
			if(a[i]=='4')
			{
				count2-=10;
			}
		}
			
		if(count2>=5)
		{
			cout<<a<<endl;
			count1++;
		}
	}
	cout<<count1<<endl;	
}
