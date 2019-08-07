include <cmath>

int cnt;

int f(int now, int a, int b)
{
    if(now==1){
        if(a==cnt && b==2*cnt) return 1;
        return 0;
    }
    if(b>2*cnt) return 0;
    if(a>cnt) return 0;
    if(a>b/2) return 0;
    int ret=0;
    if(now%3==0) ret+=f(now/3,a+1,b);
    ret+=f(now-1,a,b+1);
    return ret;
}

int solution(int n) {
    cnt=log(n)/log(3);
    return f(n-2,0,2);
}
