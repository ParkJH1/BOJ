#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    vector<int> dp(n+1);
    dp[0]=dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n; i++) dp[i]=dp[i-1]+dp[i-2];
    cin>>m;
    int a=1;
    int answer=1;
    while(m--){
        int b;
        cin>>b;
        answer*=dp[b-a];
        a=b+1;
    }
    answer*=dp[n-a+1];
    cout<<answer;
    
    return 0;
}
