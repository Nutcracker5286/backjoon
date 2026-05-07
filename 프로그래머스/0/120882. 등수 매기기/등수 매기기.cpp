#include <string>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer(score.size(),1);
    vector<pair<int,int>> rank; // 평균 점수, 인덱스
    int idx=0;
    for(auto c : score){
        rank.push_back({(c[0]+c[1]),idx++});
    }
    
    sort(rank.begin(),rank.end(),greater<pair<int,int>>{});
    int bef = 0, rate=1;
    
    for(int i=0; i<rank.size(); i++){
        int curR = i+1;
        
        if(i>0 && rank[i].first == rank[i-1].first){
            curR = answer[rank[i-1].second];
        }
        int oriIdx = rank[i].second;
        answer[oriIdx] =curR;
    }
    

    
    return answer;
}