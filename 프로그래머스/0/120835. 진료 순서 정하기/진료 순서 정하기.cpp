#include <string>
#include <bits/stdc++.h>

using namespace std;

// 응급도순으로 랭킹 매기고 주어진 배열 순대로  해당 랭킹 출력

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    answer.resize(emergency.size());
    vector<pair<int,int>> rk; //응급도 idx
    int idx= 0;
    for(auto c:emergency)
        rk.push_back({c,idx++});
    
    sort(rk.begin(),rk.end(),greater<pair<int,int>>{});
    
    idx=0;
    for(auto c : rk){
        answer[(c.second)] = 1+idx++;
    }
    
    return answer;
}