#include <string>
#include <bits/stdc++.h>

using namespace std;


/*
처음에는 문자, 처음으로 숫자 만나면 지금까지 문자열을 저장
숫자는 다음으로 문자를 만나면 종료
*/
vector<string> split(string &s,int t){
    vector<string> res;

    string cur ="",num="";
    
    // . 기준 전처리
    int pos = s.find('.');
    bool fir=0;
    for(int i=0; i<s.size(); i++){
        bool isN = isdigit(s[i]);
        if(!fir && !isN){ //초기이고 숫자가 아니면
            cur+=tolower(s[i]);
        }
        else if(!fir && isN){ //문자만 컬렉하다가 숫자 만나는 경우
            res.push_back(cur);
            fir = 1;
            num+=s[i];
        }
        else if(fir && isN ){ //초기처리 됬고 숫자만 만나는
            num+=s[i];
        }
        else if(fir && !isN){ //초기처리 됐고, 숫자가 아니면
            res.push_back(num);                
            res.push_back(to_string(t));
            return res;
        }
    }
   
        res.push_back(num);                
            res.push_back(to_string(t));
    
        
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