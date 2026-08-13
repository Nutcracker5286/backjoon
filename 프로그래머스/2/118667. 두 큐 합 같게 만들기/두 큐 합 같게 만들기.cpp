#include <string>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
팝 , 푸쉬를 한 단위로, 두 큐의 합이 같도록 함 
두 큐의 원소의 합의 반이면 두 큐의 합이 같음
*/


int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    
    ll sum=0, sum1=0, sum2=0;
    queue<ll> q1, q2;
    for(int i=0; i<queue1.size(); i++){
        sum +=queue1[i] + queue2[i];
        sum1 +=queue1[i];
        sum2 +=queue2[i];
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }
    
    ll cnt =0;
    while(cnt <=2*queue1.size()){
        if(sum1 > sum2){ // 1번큐에서 빼야됨
        while(sum1 > sum2){
            sum1-=q1.front();
            sum2+=q1.front();
            q2.push(q1.front());
            q1.pop();
            cnt++;
        }
        if(sum1 == sum2 ){
            return cnt;
        }
    }
    else{
        while(sum2 > sum1){
            sum2-=q2.front();
            sum1+=q2.front();

            q1.push(q2.front());
            q2.pop();
            cnt++;
        }
        if(sum1 == sum2 ){
            return cnt;
        }
    }
    }
    
    
    
    
    
    
    return -1;
}