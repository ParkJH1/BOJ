/*
 0. GUI 로드
 1. 폴더 경로 입력(-> GUI에서 사용자가 선택한 폴더명 받아오기), 폴더 안에 있는 모든 파일의 경로(이름)를 구하기
 2. 각각의 파일들을 열어서 내가 찾는 문자열(pattern)이 있는 검사 - KMP
    2-0. 찾을 문자열(pattern) 입력받기
    2-1. 파일 경로로 파일 열기
    2-2. 파일 안에있는 모든 문자열을 입력받기
    2-3. KMP알고리즘 수행
 3. 2번과정에서 찾아낸 결과를 화면(->GUI)에 표시
 
 */

#include <iostream>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <fstream>

using namespace std;

/*
#include <windows.h>
void read_directory(const string& name, vector<string>& v)
{
    string pattern(name);
    pattern.append("\\*");
    WIN32_FIND_DATAA data;
    HANDLE hFind;
    if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
        do {
            v.push_back(data.cFileName);
        } while (FindNextFileA(hFind, &data) != 0);
        FindClose(hFind);
    }
}
*/

bool read_directory(const std::string& name, vector<string>& v)
{
    DIR* dirp = opendir(name.c_str());
    if(dirp==NULL){
        cout<<"Fail\n";
        return false;
    }
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        v.push_back(dp->d_name);
    }
    closedir(dirp);
    return true;
}

// KMP
void kmp(string& target, string& pattern, vector<pair<int,int>>& pos, int ln)
{
    vector<int> fail(pattern.length());
    for(int i=1,j=0; i<fail.size(); i++){
        while(j!=0 && pattern[i]!=pattern[j]) j=fail[j-1];
        if(pattern[i]==pattern[j]) fail[i]=++j;
        else fail[i]=0;
    }
    
    for(int i=0,j=0; i<target.length(); i++){
        while(j!=0 && target[i]!=pattern[j]) j=fail[j-1];
        if(target[i]==pattern[j]){
            if(j==pattern.length()-1){
                pos.push_back({ln,i-pattern.length()+2});
                j=fail[j];
            }
            else j+=1;
        }
    }
}

int main()
{
    // 1. 폴더 경로 입력, 폴더 안에 있는 모든 파일의 경로(이름)를 구하기
    string path;
    cout<<"path : ";
    cin>>path;
    vector<string> filenames;
    read_directory(path, filenames);
//    for(string& filename : filenames) cout<<filename<<"\n";
    
    // 2-0. 찾을 문자열(pattern) 입력받기
    string pattern;
    cout<<"pattern : ";
    cin>>pattern;
    
    // 2-1. 파일 경로로 파일 열기
    for(string& filename : filenames){
//        string filepath=path+"\\"+filename;
        string filepath=path+"/"+filename;
        vector<pair<int,int>> pos;
        ifstream fp(filepath.c_str());
        
        // 2-2. 파일 안에있는 모든 문자열을 입력받기
        int ln=1;
        while(fp.good()){
            string s;
            getline(fp,s);
            // 2-3. KMP알고리즘 수행
            kmp(s,pattern,pos,ln);
            ln+=1;
        }
        
        // 3. 2번과정에서 찾아낸 결과를 화면에 표시
        if(pos.empty()) cout<<"[X] ";
        else cout<<"[O] ";
        cout<<filename<<"\n";
        
        fp.close();
    }
}
