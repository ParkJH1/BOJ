#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,b;
    cin>>n>>b;
    string answer="";
    while(n!=0){
        int a=n%b;
        if(a<10) answer+='0'+a;
        else answer+='A'+a-10;
        n/=b;
    }
    reverse(answer.begin(),answer.end());
    cout<<answer;
    return 0;
}