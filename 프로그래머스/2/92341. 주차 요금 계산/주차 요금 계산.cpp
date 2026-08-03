#include <string>
#include <bits/stdc++.h>

using namespace std;

/// 공백 기준 분리


int tominute(string &a){
    
    return stoi(a.substr(0,2))*60 + stoi(a.substr(3,2));
    
}



/*
입출이 짝을 이룸
차랑별 벡터에 시간을 환산하여 삽입

홀수면 마지막 시간 기록추가

요금 보정 후 반환
*/
int baseTime, baseFee ,unitTime, unitFee;
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    baseTime  = fees[0];
    baseFee  = fees[1];
    unitTime  = fees[2];
    unitFee  = fees[3];

    vector<int> adj[10005];
    int n = records.size();
    
    for(auto re : records){
        stringstream ss(re);
        string time, num, io;
        ss>>time>>num>>io;
        
        adj[stoi(num)].push_back(tominute(time));
    }
    
    
    for(int i=0; i<10005; i++){
        if(adj[i].empty()) continue;

        string ed = "23:59";
        if(adj[i].size() %2 == 1) // 출차 기록이 없기 때문에 계속 머문것
            adj[i].push_back(tominute(ed));
        
        
        //시간 계산
        int totalTime =0;
        for(int j=1; j<adj[i].size(); j+=2){
            totalTime += adj[i][j]- adj[i][j-1];
        }
        
        
        
        //요금제 적용
        int fee =baseFee ;
        if(totalTime > baseTime){
            fee += (totalTime-baseTime + unitTime-1)
                /unitTime*unitFee;
        }
        answer.push_back(fee);
    }
    

    
    return answer;
}