#include<iostream>
#include<cstring> 
using namespace std;
int main()
{
	int n;
	char str[10001];
	cin>>n;
	while(n--)
	{
		cin>>str;
		int count=1;
		for(int i=0;i<strlen(str);i++)
		{  
            if(str[i]==str[i+1])count++;  
            else
			{  
                if(count==1) cout<<str[i];  
                else cout<<count<<str[i]; 
                count=1;  
        	}  
		}
		cout<<endl;
	}
	return 0;
}
