#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string t,p;
    cin>>t>>p;
    
    vector<int> fail(p.length());
    for(int i=1; i<p.length(); i++){
        int j=fail[i-1];
        while(true){
            if(p[j]==p[i]){
                fail[i]=j+1;
                break;
            }
            if(j==0){
                fail[i]=0;
                break;
            }
            j=fail[j-1];
        }
    }
    
    for(int i=0,j=0; i<t.length();){
        if(t[i]==p[j]){
            i+=1;
            j+=1;
            if(j==p.length()){
                cout<<i-p.length()<<" ";
                j=fail[j-1];
            }
        }
        else{
            if(j==0) i+=1;
            else j=fail[j-1];
        }
    }
    
    return 0;
}
