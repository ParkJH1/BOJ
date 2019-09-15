#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    return (b==0)?a:gcd(b,a%b);
}
int main()
{
    int a,b;
    cin>>a>>b;
    int c=gcd(a,b);
    int d=a/c*b;
    cout<<c<<"\n"<<d;
    return 0;
}