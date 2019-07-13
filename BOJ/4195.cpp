#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>

using namespace std;
using pii=pair<int,int>;
using ll=long long;

vector<int> parent;
vector<int> rnk;
vector<int> siz;

int uf_find(int a)
{
    if(parent[a]==a) return a;
    return parent[a]=uf_find(parent[a]);
}

bool uf_union(int a, int b)
{
    int ap=uf_find(a),bp=uf_find(b);
    if(ap==bp) return false;
    if(rnk[ap]>rnk[bp]) swap(ap,bp);
    parent[ap]=bp;
    siz[bp]+=siz[ap];
    if(rnk[ap]==rnk[bp]) rnk[bp]+=1;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int f;
        cin>>f;
        map<string,int> m;
        parent.clear();
        rnk.clear();
        siz.clear();
        parent.resize(2*f);
        for(int i=0; i<2*f; i++) parent[i]=i;
        rnk.resize(2*f);
        siz.resize(2*f,1);
        for(int i=0; i<f; i++){
            string a,b;
            cin>>a>>b;
            int aidx=m.insert({a,m.size()}).first->second;
            int bidx=m.insert({b,m.size()}).first->second;
            uf_union(aidx,bidx);
            cout<<siz[uf_find(aidx)]<<"\n";
        }
    }
    
    return 0;
}
