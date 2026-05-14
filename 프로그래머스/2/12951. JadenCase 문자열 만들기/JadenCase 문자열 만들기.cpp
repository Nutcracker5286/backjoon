#include <string>
#include <vector>

using namespace std;

vector<string> split(string s){
    int p =0;
    vector<string> res;
    while(p<s.size()){
        int nxt = s.find(' ',p);
        if(nxt==-1) nxt=s.size();
        if(nxt-p>0) res.push_back(s.substr(p,nxt-p));
        p = nxt+1;
    }
    return res;
}

string solution(string s) {
    string answer = "";

    char bef=' ';
    for(auto c : s){
        if(bef==' ' && !isdigit(c)){
            answer+=toupper(c);
        }
        else
        answer+=tolower(c);
        
        bef=c;
    }
    return answer;
}