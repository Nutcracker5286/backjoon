#include <string>
#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first== b.first){
        return a.second < b.second;
        
    }
    return a.first > b.first;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q; // 우선 순위, 인덱스    
    priority_queue<int> pq;
    int idx =0;
    for(auto c: priorities) {
        pq.push(c);
        q.push({c,idx++});
                            }
    
    int ord =1;
    
    while(!q.empty()){
        auto [rank,idx] =q.front(); q.pop();
        
        //우선순위가 낮으면
        if(rank < pq.top()){
            q.push({rank,idx});
        }
        else{//같으면
            if(location == idx){
                return ord;
            }
            
            pq.pop();
            ord++;
            
            
            
        }
    }

    return answer;
}