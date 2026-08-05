#include <string>
#include <bits/stdc++.h>

using namespace std;


/*
숫자 만날때까지 문자 저장
문자이후에는 끝에 도달하거나 숫자가 아니면 숫자에 저장 및 갱신

*/
vector<string> split(string &s,int t){
    vector<string> res(3);
    int i=0, n= s.size();
    
    string head ="", num ="";
    
    while(i<n && !isdigit(s[i])) head+=tolower(s[i++]);
    
    //숫자가 시작되는 지점
    int ncnt =1;
    while(i<n && isdigit(s[i]) && ncnt<=5){
        num+=s[i++];
        ncnt++;
    }
            res[0]= head; res[1] = num; res[2]=to_string(t);
    return res;
}




/*
파일명에 포함된 숫자를 반영한 정렬 기능

세 부분으로 나눔 head, number, tail
1. head 부분 기준 사전 정렬
    대소문자 구분 x,
2. 같다면 , number부분의 숫자로 정렬
3. 같다면, 원래 주어진 순서 유지
*/
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<vector<string>> confine(files.size(), vector<string>(3));
    
    for(int i=0; i<files.size(); i++){
        confine[i] = split(files[i],i); // 헤드, 넘버, 원본

        
    }
    
    stable_sort(confine.begin(),confine.end(),
        [&](auto &a, auto &b){
            if(a[0] == b[0]){
                return stoi(a[1]) < stoi(b[1]);
            }
            return a[0] < b[0];
        }
        );
    for(auto c : confine){
        answer.push_back(files[stoi(c[2])]);
        // cout<<c[0]<<" "<<c[1]<<'\n';
    }
    
    
    
    
    return answer;
}