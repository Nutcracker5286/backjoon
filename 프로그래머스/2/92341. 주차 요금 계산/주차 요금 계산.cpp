#include <string>
#include <bits/stdc++.h>

using namespace std;

/// 공백 기준 분리
vector<string> split(char op, string &str){
    int pos=0;
    vector<string> res;
    while(pos<str.size()){
        int nxt = str.find(op,pos);
        if(nxt == -1) nxt = str.size();
        if(nxt-pos>0)  res.push_back(str.substr(pos,nxt-pos));
        pos =nxt+1;
        
    }
    return res;
    
}

int tonum(string &a){
    return (a[0]-'0')*10 +(a[1]-'0') ;
    
}

int calcTime(string &a, string &b){
    vector<string> timeA = split(':',a);
    vector<string> timeB = split(':',b);   
    int tA = tonum(timeA[0])*60 + tonum(timeA[1]);
    int tB = tonum(timeB[0])*60 + tonum(timeB[1]);
    return tB - tA;
}



/*
입출이 짝을 이룸

레코드 탐색
탐색시 공백기준 분리
첫번째map에 있으면 
    시간 차이 계산
    다른 맵에 번호와 시간 저장
    맵에서 삭제
없으면 번호와 시간 저장

첫번째 map에 남아있으면 정각 기준으로 계산 및 반환하고
다른 맵에 시간을 더해서 저장

벡터에 페어로  번호 시간 저장
소팅후
반환
*/
int baseTime, baseFee ,unitTime, unitFee;
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    baseTime  = fees[0];
    baseFee  = fees[1];
    unitTime  = fees[2];
    unitFee  = fees[3];

    unordered_map<string, string> ioMap;
    unordered_map<string, int> timeMap;

// 없으면 번호와 시간 저장

// 첫번째 map에 남아있으면 정각 기준으로 계산 및 반환하고
// 다른 맵에 시간을 더해서 저장

// 벡터에 페어로  번호 시간 저장
// 소팅후
// 반환
    
    for(string v : records){
        //항으로 분리
        vector<string> cmd = split(' ',v);
        string curT=cmd[0],  curN = cmd[1];
        
        // 입출차 기록에 있는 경우
        if(ioMap.find(curN)!=ioMap.end()){
            // 시간 차이 계산
            int diff = calcTime(ioMap[curN], curT);
          
            // 다른 맵에 번호와 시간 저장
            timeMap[curN] +=diff;
            
            // io맵에서 삭제
            ioMap.erase(ioMap.find(curN));
        }
            
        else
        //없는 경우
        ioMap[curN] = curT;
        
        
    }
    
    
//io map에 남아있으면 정각 기준으로 계산 및 반환하고
// time맵에 시간을 더해서 저장
    for(auto [curN,curT] : ioMap){
        string stTime = "23:59";
        int sum  = calcTime(curT, stTime);
        timeMap[curN]+=sum;
       
    }
    
    
    //time 맵 순회하면서 벡터에 번호 ,시간 저장
    vector<pair<int,int>> res;
    for(auto [N , T] :timeMap){
        
        int cur =0;
        for(int i=0; i<N.size(); i++){
            if(isdigit(N[i])){
                cur=cur*10 +N[i]-'0';
            }
            else{
                cur =0;
            }
        }
        
        
        res.push_back({cur,T});
    }
    
    //소팅 후 반환
    sort(res.begin(),res.end());

    
    
    // int baseTime, baseFee ,unitTime, unitFee
    for(auto c: res){
        int curT = c.second;
        int curFee;
        if(curT <= baseTime) curFee = baseFee;
        else{
            curFee = baseFee
                +((curT - baseTime+unitTime-1)/unitTime)
                *unitFee;
        }
        answer.push_back(curFee);
        
    }
    
    return answer;
}