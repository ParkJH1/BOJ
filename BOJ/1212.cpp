#include <iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    if(s[0]=='0'){
        cout<<0;
        return 0;
    }
    string answer="";
    for(int i=0; i<s.length(); i++){
        int n=s[i]-'0';
        if(n>=4){
            answer+='1';
            n-=4;
        }
        else answer+='0';
        if(n>=2){
            answer+='1';
            n-=2;
        }
        else answer+='0';
        if(n>=1) answer+='1';
        else answer+='0';
    }
    int i=0;
    while(answer[i]=='0') i+=1;
    for(; i<answer.length(); i++) cout<<answer[i];
    return 0;
}