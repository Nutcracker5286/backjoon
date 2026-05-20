#include <string>
#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s){
    int pos = 0;
    vector<string> res;
    
    while(pos < s.size()){
        int nxt= s.find(',',pos);
        if(nxt==-1) nxt =s.size();        
        if(nxt-pos>0) res.push_back(s.substr(pos,nxt-pos));
        pos=nxt+1;
    }
    return res;
}

// 괄호로 덮힌 튜플들로 분리 , 가장 큰 사이즈가 전체 튜플의크기
// 가장 작은 사이즈가 올바른 순서, 울바른순서가 유지되도록 정답에 추가
vector<int> solution(string s) {
    vector<int> ans;
    
    string num ="";
    
    vector<vector<int>> brt;
    vector<int> cur;
    for(auto c:  s){
        if(isdigit(c)){
            num+=c;
        }
        else{ //숫자가 아니면 남은 수열 처리
            //num이 비어있는게 아니라면, 일단 수열이 끝난것이기에 집어넣은
            if(!num.empty()){
                cur.push_back(stoi(num));
                num ="";
            }
            
            //닫는 괄호이고 현재 벡터 수열이 있다면 -> 현재 수열이 끝난것
            if(c=='}' && !cur.empty()){
                brt.push_back(cur);
                cur.clear();
            }
        }
    }

    sort(brt.begin(), brt.end(), [](auto &a , auto &b){ return a.size()<b.size();});
    
    
    //이전 수열의 없는 값을 바로 뒤에 추가하면 올바른 튜플의 순서
    set<int> cnt;
    for(auto arr :brt){
        for(auto c: arr){
            if(cnt.count(c)==0){
                cnt.insert(c);
                ans.push_back(c);
            }
        }
    }

    return ans;
}