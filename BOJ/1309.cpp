#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> dp(n,vector<int>(3));
    dp[0][0]=dp[0][1]=dp[0][2]=1;
    for(int i=1; i<n; i++){
        dp[i][0]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%9901;
        dp[i][1]=(dp[i-1][0]+dp[i-1][2])%9901;
        dp[i][2]=(dp[i-1][0]+dp[i-1][1])%9901;
    }
    cout<<accumulate(dp[n-1].begin(),dp[n-1].end(),0)%9901;
    return 0;
}
