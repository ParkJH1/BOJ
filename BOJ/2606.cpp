#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> siz;

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
    if(siz[ap]>siz[bp]) swap(ap,bp);
    parent[ap]=bp;
    siz[bp]+=siz[ap];
}

int main()
{
    int n,m;
    cin>>n>>m;
    parent.resize(n);
    for(int i=0; i<n; i++) parent[i]=i;
    siz.resize(n,1);
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        a-=1;
        b-=1;
        uf_union(a,b);
    }
    cout<<siz[uf_find(0)]-1;
    return 0;
}
