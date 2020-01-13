#include <stack>
#include <iostream>
#include <string>
using namespace std;
int G[1001][1001];
int N,M;
stack<int> S;
bool dfs(int u)
{ 	
    S.push(u); 
    if(G[u][0]==0)
	{
        bool flag=true;
        for(int i=1; i<=N; i++){
            if (i==u) 
				continue;
            flag=((G[i][0]==0) && flag);
        }
        if(flag==false){
            S.pop();
        }
        return flag;
    }
    for(int v=1; v<=N; v++){ 
        if(G[u][v])
		{
            //删除边
            G[u][v]-=1;
            G[v][u]-=1;
            G[v][0]-=1;
            G[u][0]-=1;
            if(dfs(v)) 
				return true;
            else
			{
				//撤销删除边
                G[u][v]+=1;
                G[v][u]+=1;
                G[v][0]+=1;
                G[u][0]+=1;
            }
        } 
    }
    S.pop();
    return false;
}
int main(){
    cin>>N>>M;//N 点 M 边 
    int u,v;
    for(int i=0; i!=M; i++){
        cin>>u>>v;
        G[u][v]+=1;
        G[v][u]+=1;
       	G[u][0]+=1;//度数 
        G[v][0]+=1;//度数 
    }
    /*寻找起点
    for(u=1; u<=N; u++){
        if(G[u][0]&1) break;//判断度数的奇偶 
    }
    if(u==N+1) dfs(1);
    else dfs(u);
    */
	dfs(1); 
    while(!S.empty())
	{
        cout<<S.top()<<" ";
        S.pop();
    }
    cout<<endl;
    return 0;
}
