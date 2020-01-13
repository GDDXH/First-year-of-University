#include<iostream>
#include<vector> 
#include<cstring>
#include<cstdio>
#include<stack>
#define MAXN 501    //����
#define MAXM 1030   //����
using namespace std;
int map[MAXN][MAXN];//�ڽӾ���
int degree[MAXN];//���� 
stack<int>S;//ջ 
vector<int> vec;//��¼��
vector<int> path; 
int size;
void DFS(int u)
{
	//����õ��������ĵ㣬��ô�ͼ������֮�У�������Щ�㣬ֱ��û�������ĵ㡣
	//cout<<"ִ��2     "<<u<<endl; 
    S.push(u);
    for(int i=0;i<size;i++)
    {
        if(map[u][vec[i]])//����ǰ�ĵ㣬ɾ���߹��������ߣ����������ڵĵ��Ͻ���ͬ���Ĳ���������ɾ���ĵ���뵽·����ȥ��
        {
            map[u][vec[i]]--;//ɾ���� 
            map[vec[i]][u]--;//ɾ���� 
            DFS(vec[i]);
            break;
        }
    }
}
void  fleury(int u)
{
	/*
	��ĳ���ڵ㿪ʼ��Ȼ����һ������������ص������Ļ�·�������ַ�������֤ÿ���߶���������
	�����ĳ����ı�û�б��������������Ϊ��㣬������Ϊ��ʼ�ߣ������͵�ǰ�Ļ��ν��ϡ�
	����ֱ�����еı߶�������������������ͼ�ͱ����ӵ�һ���ˡ�
	*/ 
    bool flag;//�Ƿ���������ı�  
    while(!S.empty()) 
		S.pop();//��ջ 
    S.push(u);//��ջ 
    while(!S.empty())
    {
        flag=false;
        u=S.top();//����ջ�� 
		S.pop();//��ջ 
        for(int i=0;i<size;i++) //����������ı� 
        {
            if(map[u][vec[i]])
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
        	//cout<<"ִ��1    "<<u<<endl; 
            DFS(u);	
		}

        else//�����ʱ��õ��������ĵ㣬��ô�ͼ���·���� 
        {
			path.push_back(u);
			//cout<<"path: "<<u<<endl; 
		} 

    }
}
int main()
{
    int m,u,v,i;
    while(scanf("%d",&m)==1)
    {
		path.clear();
    	vec.clear();
        memset(map,0,sizeof(map));
        memset(degree,0,sizeof(degree));
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            map[u][v]++;
            map[v][u]++;
            degree[u]++;
            degree[v]++;
            vec.push_back(u);
            vec.push_back(v);
        }
        size = vec.size(); 
        /*
        for(i=0;i<size;i++){
            if(degree[vec[i]]%2==1){
          		cout<<"��ȶ���"<<endl;
				break;  	
			}
        }
        */
     	fleury(vec[0]);
        for(i=0;i<path.size();i++)
        {
        	cout<<path[i]<<"->";
        }
        cout<<endl;
    }
    return 0;
}
