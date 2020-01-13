#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
using namespace std;
bool cmp(string a,string b)
{
	if(a.length()!=b.length())
		return a.length()<b.length();
	int len = a.size();
	for(int i=0;i<len;i++)
	{
		if(a[i]!=b[i])
			return a[i]<b[i];
	}
	return 1;
}
int main()
{
	int N;
	while(cin>>N,N)
	{
		map<string,int> temp;
		string s ,front[1010],behind[1010];
		vector<string> re;
		for(int i=0;i<N;i++)
		{
			cin>>s;
			front[i] = s;
			sort(s.begin(),s.end());
			behind[i] = s;
			temp[s]++;
		}
		for(int i=0;i<N;i++)
		{
			if(temp[behind[i]] == 1)
				re.push_back(front[i]);
		}
		sort(re.begin(),re.end(),cmp);
		if(re.empty())
			cout<<"None"<<endl;
		else
		{
			cout<<re[0];
			for(int i=1;i<re.size();i++)
				cout<<' '<<re[i];
			cout<<endl;
		}	
	}
 } 
