#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*
전화번호별로, 전화번호 자기 자신 전까지 set이나 언오더에 넣어놓은 중에서 찾기
한번이라도 찾으면 거짓 반환 후 종료
*/

set<string> len[21];

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    set<string> set(phone_book.begin(),phone_book.end());
    
    for(auto c : phone_book){
        string pfix ="";
        for(int i=0; i<c.size()-1; i++){
            pfix+=c[i];
            if(set.find(pfix)!=set.end()){
                return false;
            }
        }
    }
    
    
    return true;
}