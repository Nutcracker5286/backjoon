#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*
참가자를 전부 멀티셋에 삽입
완주자 탐색
    탐색 진행하면서 find해서 있으면 삭제
ans에 삽입 
*/

string solution(vector<string> participant, vector<string> completion) {
    
    
    string answer = "";
    
    multiset<string> pc(participant.begin(),participant.end());
    for(auto c : completion){
        if(pc.find(c) != pc.end()){
            pc.erase(pc.find(c));
        }
    }
    
    for(auto c: pc){
        answer+=c;
    }
    
    
    return answer;
}