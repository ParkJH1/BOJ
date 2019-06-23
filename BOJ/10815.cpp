#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    cin>>m;
    while(m--){
        int tmp;
        cin>>tmp;
        auto ret=lower_bound(v.begin(),v.end(),tmp);
        if(ret!=v.end() && *ret==tmp) cout<<"1 ";
        else cout<<"0 ";
    }
    return 0;
}
