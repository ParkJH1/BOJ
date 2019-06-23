#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using ll=long long;

int main()
{
    int k,n;
    cin>>k>>n;
    vector<ll> lan(k);
    for(int i=0; i<k; i++) cin>>lan[i];
    ll lo=0,hi=(ll)INT_MAX+1;
    while(lo<hi){
        ll mid=(lo+hi)/2;
        ll midvalue=0;
        for(int i=0; i<k; i++) midvalue+=lan[i]/mid;
        if(midvalue>=(ll)n) lo=mid+1;
        else hi=mid;
    }
    cout<<lo-1<<"\n";
}
