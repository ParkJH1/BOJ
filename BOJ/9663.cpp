#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int n;
int v[20][20]={0};

int answer=0;

// 체스말 배치하는 재귀함수
void dfs(int y, int x, int cnt)
{
    // 배치된 체스말이 n개일 경우 정답 +1
    if(cnt==n){
        answer+=1;
        return;
    }
    // 현재 기록된 체스말에 의해 배치가 불가능한 지점을 기록하는 tmp배열
    int tmp[20][20]={0};
    int i,j;
    v[y][x]=1;
    for(i=0; i<n; i++){
        if(i==y) continue;
        if(v[i][x]==0){
            v[i][x]=-1;
            tmp[i][x]=-2;
        }
    }
    for(i=0; i<n; i++){
        if(i==x) continue;
        if(v[y][i]==0){
            v[y][i]=-1;
            tmp[y][i]=-2;
        }
    }
    i=y;
    j=x;
    while(1){
        i+=1;
        j+=1;
        if(i<0 || i>=n || j<0 || j>=n) break;
        if(v[i][j]==0){
            v[i][j]=-1;
            tmp[i][j]=-2;
        }
    }
    i=y;
    j=x;
    while(1){
        i-=1;
        j-=1;
        if(i<0 || i>=n || j<0 || j>=n) break;
        if(v[i][j]==0){
            v[i][j]=-1;
            tmp[i][j]=-2;
        }
    }
    i=y;
    j=x;
    while(1){
        i+=1;
        j-=1;
        if(i<0 || i>=n || j<0 || j>=n) break;
        if(v[i][j]==0){
            v[i][j]=-1;
            tmp[i][j]=-2;
        }
    }
    i=y;
    j=x;
    while(1){
        i-=1;
        j+=1;
        if(i<0 || i>=n || j<0 || j>=n) break;
        if(v[i][j]==0){
            v[i][j]=-1;
            tmp[i][j]=-2;
        }
    }
    
    // 다음 체스말을 배치가능한 곳에 배치
    if(y+1<n){
        for(i=0; i<n; i++){
            if(v[y+1][i]==0) dfs(y+1,i,cnt+1);
        }
    }
    
    // 탐색이 끝난 후 tmp에 기록된 지점들을 원상복구
    v[y][x]=0;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(tmp[i][j]==-2){
                v[i][j]=0;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d",&n);
    int i=0;
    // 첫번째 행의 각 열에 체스말을 배치하면서 정답 기록
    for(i=0; i<n; i++){
        dfs(0,i,1);
    }
    printf("%d",answer);
    return 0;
}
