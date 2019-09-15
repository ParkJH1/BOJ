#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> answer;
    while(n!=0){
        int nn=n/-2;
        if(n-nn*-2<0) nn+=1;
        answer.push_back(n-nn*-2);
        n=nn;
    }
    if(answer.empty()) cout<<"0";
    else for(auto it=answer.rbegin(); it!=answer.rend(); it++) cout<<*it;
    return 0;
}