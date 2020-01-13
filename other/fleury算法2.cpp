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
            //ɾ����
            G[u][v]-=1;
            G[v][u]-=1;
            G[v][0]-=1;
            G[u][0]-=1;
            if(dfs(v)) 
				return true;
            else
			{
				//����ɾ����
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
    cin>>N>>M;//N �� M �� 
    int u,v;
    for(int i=0; i!=M; i++){
        cin>>u>>v;
        G[u][v]+=1;
        G[v][u]+=1;
       	G[u][0]+=1;//���� 
        G[v][0]+=1;//���� 
    }
    /*Ѱ�����
    for(u=1; u<=N; u++){
        if(G[u][0]&1) break;//�ж϶�������ż 
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
