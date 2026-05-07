#include <string>
#include <vector>

using namespace std;
vector<int> split(string ori){
    int pos=0;
    vector<int> res;
    while(pos<ori.size()){
        int nxt = ori.find(" + ",pos);
        if(nxt==-1) nxt=ori.size();
        if(nxt-pos>0) res.push_back(stoi(ori.substr(pos,nxt-pos)));
        pos=nxt+3;
    }
    return res;
}

string solution(string poly) {
    string answer = "";
    string ch = "";
    int x=0, c=0;
    int tmp =0;
    for(int i =0; i<poly.size(); i++){
        if(isdigit(poly[i])){
            tmp=tmp*10 + poly[i]-'0';
        }
        else if(poly[i]=='+'){
            c+=tmp;
            tmp=0;
        }
        else if (poly[i]=='x'){
            if(tmp ==0) tmp=1;
            x+=tmp;
            tmp=0;
        }
    }
    c+=tmp;
    
    if(x>0){
        if(x==1) answer+="x";
        else
            answer+=to_string(x)+"x";
    }
    if(c>0){
        if(!answer.empty())
        answer+=" + "+to_string(c);
        else answer+=to_string(c);
    }
        return answer;
    
}