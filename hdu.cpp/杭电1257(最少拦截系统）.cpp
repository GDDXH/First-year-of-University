#include<iostream>
#include<vector> 
#include<cstdio> 
int main()
{
	int n,h;
	while(scanf("%d",&n)!=EOF)
	{
		std::vector<int> result;
		scanf("%d",&h);
		result.push_back(h);
		while(--n)
		{
			int min = 0x3f3f3f3f;
			int sign;
			scanf("%d",&h);
			int len = result.size();
			for (int i = 0;i<len;i++)
			{
				if(min>result[i]&&result[i]>=h)
				{
					min = result[i];
					sign = i;
				}
			} 
			if(min !=0x3f3f3f3f)
				result [sign] = h;
			else
				result.push_back(h);
		}
		printf("%d\n",result.size());
		result.clear();
	}
	return 0;
}

