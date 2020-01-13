#include<iostream>
#include<windows.h> 
#include<vector>
using namespace std;
int main()
{
	vector<int> vec(10);
	cout<<vec.size()<<endl;
	int len = vec.size();
	system("pause");
	for(int i=0;i<len;i++)
	{
		cout<<vec[i]<<endl;
	}
	vec.push_back(100); 
} 
