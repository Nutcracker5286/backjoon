#include <string>
#include <vector>

using namespace std;

vector<string> split(string ori){
    int pos =0;
    vector<string> res;
    while(pos<ori.size()){
        int nxt= ori.find(' ',pos);
        if(nxt==-1) nxt = ori.size();
        if(nxt-pos>0) res.push_back(ori.substr(pos, nxt-pos));
        pos = nxt+1;
    }
    return res;
}

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for(auto ori : quiz){
        vector<string> tk = split(ori);
        
        int left =0, right =0,st=0,sign=1;
        
        for(auto t :tk){
            if(isdigit(t[0])){ //숫자면
                if(st==0) left +=stoi(t)*sign; //좌항이면
                else right +=stoi(t)*sign; // 우항이면
            }
            else if(t.size()>1 && t[0]=='-'){ //음수인 수이면
                if(st==0) left-=stoi(t.substr(1, t.size()))*sign;
                else right-=stoi(t.substr(1, t.size()))*sign;
            }
            else if(t[0] == '+' || t[1]=='-'){
                if(t[0]=='+') sign=1;
                else sign=-1;
            }
            else st=1;
        }
        
        if(left == right)answer.push_back("O");
        else answer.push_back("X");
    }
    return answer;
}