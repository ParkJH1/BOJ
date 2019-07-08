#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> parent;
vector<int> city;

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
    cin>>n;
    cin>>m;
    parent.resize(n);
    city.resize(m);
    for(int i=0; i<n; i++) parent[i]=i;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int tmp;
            cin>>tmp;
            if(tmp==1) uf_union(i,j);
        }
    }
    for(int i=0; i<m; i++) cin>>city[i];
    int gn=uf_find(city[0]-1);
    bool answer=true;
    for(int i=1; i<m; i++){
        if(uf_find(city[i]-1)!=gn){
            answer=false;
            break;
        }
    }
    if(answer) cout<<"YES";
    else cout<<"NO";
    return 0;
}
