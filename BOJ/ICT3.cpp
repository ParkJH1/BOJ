#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// 소수 체크 함수
int isp(int n)
{
    // 1이라면 -1(1이다) 반환
    if(n==1) return -1;
    // 소수체크는 제곱근까지만
    int sqn=sqrt(n);
    int i;
    // 2부터 n의 제곱근까지 돌면서 나누어떨어지는 수가 있다면 0(합성수) 반환
    for(i=2; i<=sqn; i++){
        if(n%i==0) return 0;
    }
    // 1(소수) 반환
    return 1;
}

int main(int argc, char *argv[]) {
    int a[5];
    int i;
    for(i=0; i<5; i++) scanf("%d",&a[i]);
    for(i=0; i<5; i++){
        // 소수 체크함수 반환값으로 결과 분류
        int ret=isp(a[i]);
        if(ret==1) printf("prime number\n");
        else if(ret==0) printf("composite number\n");
        else printf("number one\n");
    }
    return 0;
}
