#include <iostream>
#include <vector>
#define MOD 10007
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1);
    dp[1]=1;
    dp[2]=3;
    for(int i=3; i<=n; i++){
        dp[i]=(dp[i-1]+2*dp[i-2])%MOD;
    }
    cout<<dp[n];
    return 0;
}