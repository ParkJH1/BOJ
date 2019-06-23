#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> cost(n,vector<int>(3));
    vector<vector<int>> dp(n,vector<int>(3,99999999));
    
    for(int i=0; i<n; i++) for(int j=0; j<3; j++) cin>>cost[i][j];
    dp[0]=cost[0];
    
    for(int i=1; i<n; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                if(j==k) continue;
                dp[i][j]=min(dp[i][j],dp[i-1][k]+cost[i][j]);
            }
        }
    }
    cout<<*min_element(dp[n-1].begin(),dp[n-1].end());
    return 0;
}
