#include <iostream>
using namespace std;
int main()
{
    string n;
    int b;
    cin>>n>>b;
    int answer=0;
    int now=1;
    for(int i=n.length()-1; i>=0; i--){
        int digit=(n[i]>='A')?n[i]-'A'+10:n[i]-'0';
        answer+=digit*now;
        now*=b;
    }
    cout<<answer;
    return 0;
}