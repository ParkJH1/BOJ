#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

pair<int,int> operator+(pair<int,int> p1, pair<int,int> p2)
{
    return {p1.first+p2.first,p1.second+p2.second};
}

int main()
{
    int n;
    scanf("%d",&n);
    pair<int,int> dyx[]={{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d",&v[i][j]);
        }
    }
    vector<int> answer;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i][j]==1){
                int cnt=1;
                queue<pair<int,int>> q;
                q.push({i,j});
                v[i][j]=-1;
                while(!q.empty()){
                    pair<int,int> now=q.front();
                    q.pop();
                    for(int k=0; k<4; k++){
                        pair<int,int> nextpos=now+dyx[k];
                        if(nextpos.first<0 || nextpos.first>=n || nextpos.second<0 || nextpos.second>=n) continue;
                        if(v[nextpos.first][nextpos.second]==1){
                            v[nextpos.first][nextpos.second]=-1;
                            cnt+=1;
                            q.push(nextpos);
                        }
                    }
                }
                answer.push_back(cnt);
            }
        }
    }
    sort(answer.begin(),answer.end());
    cout<<answer.size()<<"\n";
    for(int ans : answer) cout<<ans<<"\n";
    return 0;
}
