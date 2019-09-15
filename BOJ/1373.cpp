#include <iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    for(int i=0; i<s.length()%3; i++) s='0'+s;
    string answer="";
    for(int i=0; i<s.length(); i+=3){
        answer+=(s[i]-'0')*4+(s[i+1]-'0')*2+s[i+2];
    }
    cout<<answer;
    return 0;
}