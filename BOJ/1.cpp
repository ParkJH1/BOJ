#include <iostream>
#include <vector>
using namespace std;

int n,k;
vector<vector<int>> v;

int dfs(int y, int x, int dir)	// 0 ~ 4
{
	if(y==n-1 && x==n) return 0;
	if(y<0 || y>=n || x<0 || x>=n) return 987654321;
	int ret=987654321;
	if(dir==0){
		if(v[y][x]==1) ret=min(ret,dfs(y+1,x,1)+1);
		else if(v[y][x]==3) ret=min(ret,dfs(y-1,x,3)+1);
		else if(v[y][x]==5) ret=min(ret,dfs(y,x+1,0)+1);
	}
	else if(dir==1){
		if(v[y][x]==2) ret=min(ret,dfs(y,x+1,0)+1);
		else if(v[y][x]==3) ret=min(ret,dfs(y,x-1,2)+1);
		else if(v[y][x]==4) ret=min(ret,dfs(y+1,x,1)+1);
	}
	else if(dir==2){
		if(v[y][x]==0) ret=min(ret,dfs(y+1,x,1)+1);
		else if(v[y][x]==2) ret=min(ret,dfs(y-1,x,3)+1);
		else if(v[y][x]==5) ret=min(ret,dfs(y,x-1,2)+1);
	}
	else if(dir==3){
		if(v[y][x]==0) ret=min(ret,dfs(y,x+1,0)+1);
		else if(v[y][x]==1) ret=min(ret,dfs(y,x-1,2)+1);
		else if(v[y][x]==4) ret=min(ret,dfs(y-1,x,3)+1);
	}
	
	return ret;
}

int main()
{
	cin>>n>>k;
	v.resize(n,vector<int>(n));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>v[i][j];
		}
	}
	
	int answer=987654321;
	if(k==0){
		answer=min(answer,dfs(0,0,0));
	}
	else{
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				for(int tile=0; tile<6; tile++){
					if(v[i][j]==tile) continue;
					int tmp=v[i][j];
					v[i][j]=tile;
					answer=min(answer,dfs(0,0,0));
					v[i][j]=tmp;
				}
			}
		}
	}
	
	if(answer==987654321) cout<<-1;
	else cout<<answer;
	
	return 0;
}
