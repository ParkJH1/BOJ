#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n));
    vector<vector<int>> dp(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin>>v[i][j];
        }
    }
    dp[0][0]=v[0][0];
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j-1>=0) dp[i][j]=dp[i-1][j-1]+v[i][j];
            if(j<i) dp[i][j]=max(dp[i][j],dp[i-1][j]+v[i][j]);
        }
    }
    cout<<*max_element(dp[n-1].begin(),dp[n-1].end());
    
    return 0;
}
