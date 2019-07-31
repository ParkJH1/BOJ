#include <iostream>
#include <vector>
using namespace std;

int n,answer;
vector<int> check1(15),check2(30),check3(30);

void dfs(int y, int x, int cnt)
{
    if(cnt==n){
        answer+=1;
        return;
    }
    if(y==n-1) return;
    check1[x]+=1;
    check2[y+x]+=1;
    check3[y-x+n]+=1;
    for(int i=0; i<n; i++){
        if(check1[i]==0 && check2[y+1+i]==0 && check3[y+1-i+n]==0) dfs(y+1,i,cnt+1);
    }
    check1[x]-=1;
    check2[y+x]-=1;
    check3[y-x+n]-=1;
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++) dfs(0,i,1);
    cout<<answer;
    return 0;
}
