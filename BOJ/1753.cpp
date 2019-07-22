#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int v,e;
    cin>>v>>e;
    int k;
    cin>>k;
    vector<vector<pair<int,int>>> adj(v+1);
    for(int i=0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vector<int> dist(v+1,987654321);
    dist[k]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,k});
    while(!pq.empty()){
        auto now=pq.top();
        pq.pop();
        now.first*=-1;
        if(dist[now.second]<now.first) continue;
        for(auto nxt : adj[now.second]){
            if(dist[nxt.first]>dist[now.second]+nxt.second){
                dist[nxt.first]=dist[now.second]+nxt.second;
                pq.push({-dist[nxt.first],nxt.first});
            }
        }
    }
    for(int i=1; i<=v; i++){
        if(dist[i]==987654321) cout<<"INF\n";
        else cout<<dist[i]<<"\n";
    }
    return 0;
}
