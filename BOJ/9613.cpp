#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b)
{
    return (b==0)?a:gcd(b,a%b);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        long long answer=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                answer+=gcd(a[i],a[j]);
            }
        }
        cout<<answer<<"\n";
    }
    return 0;
}