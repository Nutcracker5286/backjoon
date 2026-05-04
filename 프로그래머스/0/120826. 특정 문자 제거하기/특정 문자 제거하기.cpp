#include <string>
#include <bits/stdc++.h>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    vector<string> res; 
    int pos= 0;
    while(pos <= my_string.size()){
        int nxt_pos = my_string.find(letter, pos);
        if(nxt_pos == -1){
            nxt_pos = my_string.size();
        }
        if(nxt_pos-pos>0) answer+=my_string.substr(pos, nxt_pos-pos);
        pos=nxt_pos+letter.size();
    }

    return answer;
}