#include <string>
#include <bits/stdc++.h>

using namespace std;

string toBi(int t){
    string res="";
    while(t!=0){
        res+=to_string(t%2);
        t/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}

vector<int> solution(string s) {
    vector<int> answer;
    int bcnt =0, zcnt=0;
    while(s!="1"){
        string tmp ="";
        // 0 제거
        for(auto c: s){
            if(c=='0'){
                zcnt++;
                continue;
            }
            tmp+=c;
        }
        
        //길이를 2진법으로 표현
        s=toBi(tmp.size());
        bcnt++;
    }
    answer.push_back(bcnt);
    answer.push_back(zcnt);
    return answer;
}