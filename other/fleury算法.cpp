#include<iostream>
#include<vector> 
#include<cstring>
#include<cstdio>
#include<stack>
#define MAXN 501    //顶点
#define MAXM 1030   //边数
using namespace std;
int map[MAXN][MAXN];//邻接矩阵
int degree[MAXN];//度数 
stack<int>S;//栈 
vector<int> vec;//记录点
vector<int> path; 
int size;
void DFS(int u)
{
	//如果该点有相连的点，那么就加入队列之中，遍历这些点，直到没有相连的点。
	//cout<<"执行2     "<<u<<endl; 
    S.push(u);
    for(int i=0;i<size;i++)
    {
        if(map[u][vec[i]])//处理当前的点，删除走过的这条边，并在其相邻的点上进行同样的操作，并把删除的点加入到路径中去。
        {
            map[u][vec[i]]--;//删除边 
            map[vec[i]][u]--;//删除边 
            DFS(vec[i]);
            break;
        }
    }
}
void  fleury(int u)
{
	/*
	从某个节点开始，然后查出一个从这个出发回到这个点的环路径。这种方法不保证每个边都被遍历。
	如果有某个点的边没有被遍历就让这个点为起点，这条边为起始边，把它和当前的环衔接上。
	这样直至所有的边都被遍历。这样，整个图就被连接到一起了。
	*/ 
    bool flag;//是否有相关联的边  
    while(!S.empty()) 
		S.pop();//出栈 
    S.push(u);//入栈 
    while(!S.empty())
    {
        flag=false;
        u=S.top();//访问栈顶 
		S.pop();//出栈 
        for(int i=0;i<size;i++) //搜索相关联的边 
        {
            if(map[u][vec[i]])
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
        	//cout<<"执行1    "<<u<<endl; 
            DFS(u);	
		}

        else//如果此时与该点无相连的点，那么就加入路径中 
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
          		cout<<"奇度顶点"<<endl;
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
