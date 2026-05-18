#include <string>
#include <bits/stdc++.h>

using namespace std;

// 완료 날짜로 변환 -> 스택에 있는날짜보다 크면 스택이 빌땨까지 팝 아니면 스택에 삽입
vector<int> solution(vector<int> prog, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> day;
    stack<int> st;
    
    // 변환
    for(int i=0; i<speeds.size(); i++){
        int t = (100-prog[i]+speeds[i]-1)/speeds[i];
        
        day.push_back(t);
    }
    
    
    //스택으로 탐색
    int std = day[0];
    for(int i=0; i<day.size(); i++){
        if(st.empty()){
             st.push(day[i]);
            continue;
        }
        
        // 더 빠르게 해결되는 경우
        if(std>= day[i]){
            st.push(day[i]);
            continue;
        }
        
        // 더 늦게 해결되는 경우, 스택을 비우고 정답에 개수 추가
        std = day[i];
        answer.push_back(st.size());
        while(!st.empty()) st.pop();
        st.push(day[i]);
        
    }
    if(!st.empty()) answer.push_back(st.size());
    return answer;
}