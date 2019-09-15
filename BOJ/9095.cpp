#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    vector<int> dp(12);
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(int i=4; i<=11; i++) dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    while(t--){
        int n;
        cin>>n;
        cout<<dp[n]<<"\n";
    }
    return 0;
}