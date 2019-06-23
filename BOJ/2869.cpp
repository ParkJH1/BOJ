#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll=long long;

int main()
{
    ll a,b,v;
    cin>>a>>b>>v;
    
    
    ll lo=1,hi=1000000001;
    while(lo<hi){
        ll mid=(lo+hi)/2;
        if((a-b)*mid+b<v) lo=mid+1;
        else hi=mid;
    }
    cout<<lo;
    
    return 0;
}
