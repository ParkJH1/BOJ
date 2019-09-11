#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    queue<int> q;
    vector<int> dp(n+1,-1);
    q.push(1);
    dp[1]=0;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        if(now==n) break;
        if(now*3<=n && dp[now*3]==-1){
            dp[now*3]=dp[now]+1;
            q.push(now*3);
        }
        if(now*2<=n && dp[now*2]==-1){
            dp[now*2]=dp[now]+1;
            q.push(now*2);
        }
        if(now+1<=n && dp[now+1]==-1){
            dp[now+1]=dp[now]+1;
            q.push(now+1);
        }
    }
    cout<<dp[n];
    return 0;
}