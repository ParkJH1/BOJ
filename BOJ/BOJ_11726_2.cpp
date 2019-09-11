// 피보나치
#include <iostream>
#define MOD 10007
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a=1,b=2,c;
    if(n==1) cout<<a;
    else if(n==2) cout<<b;
    else{
        while(n>2){
            c=(a+b)%MOD;
            a=b;
            b=c;
            n-=1;
        }
        cout<<c;
    }
    return 0;
}