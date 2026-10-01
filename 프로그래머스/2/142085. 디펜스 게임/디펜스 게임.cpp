#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    //사용한 병사 수
    int esum=0;
    
    //무적권을 사용하는 병사들
    priority_queue<int, vector<int> , greater<int>> pq; 
    for(int i=0; i<enemy.size(); i++){
        pq.push(enemy[i]);
        
        if(pq.size() <=k) 
            continue;
        esum +=pq.top();
        pq.pop();
        
        //무적권을 다 써도 커버 불가능한 경우
        if(esum > n )
            return i;
    }
    

    return enemy.size();
}