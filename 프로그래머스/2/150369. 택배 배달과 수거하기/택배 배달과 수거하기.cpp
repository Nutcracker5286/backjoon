#include <string>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
long long solution(int cap, int n, vector<int> dels, vector<int> pis) {
    long long answer = 0;
    
    
    ll d=0,p=0; // 현재 배달 || 수거에 대한 수요
    
    for(ll i = n-1; i>=0; i--){
        d +=dels[i];
        p+=pis[i];
        
        if(d<=0 && p<=0) continue; //둘다 없는 경우면 다음 단계
        
        ll needD  = (max(0LL,d)+cap-1) /cap;
        ll needP  = (max(0LL,p)+cap-1) /cap;
        ll trips = max(needP, needD);
        answer+= 2*trips*(i+1);
        d -=trips*cap;
        p-=trips*cap;
    }
    
    
    
    
    return answer;
}