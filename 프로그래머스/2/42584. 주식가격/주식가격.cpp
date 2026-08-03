#include <string>
#include <bits/stdc++.h>

using namespace std;



/*
스택에 현재 초와 가격 삽입
top의 가격 > 현재 노드
임시 벡터에 현재 초, 현재초와 top의 초 삽입
이면 팝


*/
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<pair<int,int>> tmp; //해당노드 초 , 떨어지지 않은 기간
    stack<pair<int,int>> st; //해당노드의 초, 가격
    
    int t=0;
    for(auto p :prices){
        t++;
        while(!st.empty() && st.top().second > p){
            tmp.push_back({st.top().first,t-st.top().first});
            st.pop();
            
        }
        st.push({t,p});
        
    }
    
    while(!st.empty()){
            tmp.push_back({st.top().first,
                           prices.size()-st.top().first});
        st.pop();
    }
    sort(tmp.begin(),tmp.end());
    
    for(auto c : tmp)
        answer.push_back(c.second);
    
    
    
    return answer;
}