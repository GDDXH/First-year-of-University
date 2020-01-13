#include<iostream>
#include<iomanip>
#include<string>
#include<map>
using namespace std;
int main()
{
	int sum = 0;
	string s;
	map<string,int>word;
	while(cin>>s)
	{
		int len = s.size();
		if(isalnum(s[len-1])==0)
		{
			s = s.substr(0,len-1); 
			if(s=="")
				continue;
		}
		word[s]++;
		sum++;
	}
	for(map<string,int>::iterator it=word.begin();it!=word.end();it++)
	{
		double t=it->second*100.0/sum;
		cout.precision(2);
		cout<<setw(15)<<it->first<<":"<<setw(2)<<it->second<<" "<<setw(5)<<fixed<<t<<"%"<<endl;
	}
}
