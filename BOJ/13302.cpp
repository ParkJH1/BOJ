#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>

#define INF 987654321

using namespace std;
using pii=pair<int,int>;
using ll=long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n+1,vector<int>(50,INF));
    vector<bool> rest(n+1);
    for(int i=0; i<m; i++){
        int tmp;
        cin>>tmp;
        rest[tmp]=true;
    }
    dp[1][0]=(rest[1])?0:10000;
    if(n>=3) dp[3][1]=25000;
    if(n>=5) dp[5][2]=37000;
    for(int i=2; i<=n; i++){
        if(rest[i]){
            for(int j=0; j<50; j++){
                dp[i][j]=min(dp[i][j],dp[i-1][j]);
            }
        }x
        for(int j=0; j<50; j++){
            dp[i][j]=min(dp[i][j],dp[i-1][j]+10000);
            if(i>=3 && j>=1) dp[i][j]=min(dp[i][j],dp[i-3][j-1]+25000);
            if(i>=5 && j>=2) dp[i][j]=min(dp[i][j],dp[i-5][j-2]+37000);
        }
        for(int j=3; j<50; j+=3){
            for(int k=0; k<50; k++){
                if(i>=j/3 && k+j<50) dp[i][k]=min(dp[i][k],dp[i-j/3][k+j]);
            }
        }
    }

    cout<<*min_element(dp[n].begin(),dp[n].end());

    return 0;
}
