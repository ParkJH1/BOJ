#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> parent;

int uf_find(int a)
{
    if(parent[a]==a) return a;
    return parent[a]=uf_find(parent[a]);
}

void uf_union(int a, int b)
{
    int ap=uf_find(a);
    int bp=uf_find(b);
    if(ap==bp) return;
    parent[max(ap,bp)]=min(ap,bp);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    parent.resize(n+1);
    for(int i=0; i<=n; i++) parent[i]=i;
    while(m--){
        int c,a,b;
        cin>>c>>a>>b;
        if(c==0) uf_union(a,b);
        else{
            if(uf_find(a)==uf_find(b)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}
