#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> dp;
    for(int i=0; i<n; i++) cin>>v[i];
    for(int i=0; i<n; i++){
        auto ret=lower_bound(dp.begin(),dp.end(),v[i]);
        if(ret==dp.end()) dp.push_back(v[i]);
        else *ret=v[i];
    }
    cout<<dp.size();
    return 0;
}
