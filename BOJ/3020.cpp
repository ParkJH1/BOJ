#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,h;
    cin>>n>>h;
    vector<int> v[2];
    vector<int> answer(n+1);
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        v[i%2].push_back(tmp);
    }
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    for(int i=1; i<=h; i++){
        int cnt=0;
        int lo=0,hi=v[0].size();
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(v[0][mid]<i) lo=mid+1;
            else hi=mid;
        }
        cnt+=v[0].size()-lo;
        lo=0,hi=v[1].size();
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(v[1][mid]<h-i+1) lo=mid+1;
            else hi=mid;
        }
        cnt+=v[1].size()-lo;
        answer[cnt]+=1;
    }
    for(int i=0; i<=n; i++){
        if(answer[i]!=0){
            cout<<i<<" "<<answer[i];
            break;
        }
    }
    return 0;
}

