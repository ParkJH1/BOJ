#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<int> ind(n+1);
    vector<vector<int>> answer(n+1,vector<int>(n+1));
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[b].push_back({a,c});
        ind[a]+=1;
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(ind[i]==0){
            answer[i][i]=1;
            q.push(i);
        }
    }
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(auto nxt : adj[now]){
            ind[nxt.first]-=1;
            for(int i=1; i<=n; i++){
                answer[nxt.first][i]+=answer[now][i]*nxt.second;
            }
            if(ind[nxt.first]==0) q.push(nxt.first);
        }
    }
    for(int i=1; i<=n; i++){
        if(answer[n][i]!=0){
            cout<<i<<" "<<answer[n][i]<<"\n";
        }
    }
    return 0;
}

