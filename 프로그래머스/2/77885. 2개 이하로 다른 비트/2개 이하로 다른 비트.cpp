#include <string>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


pair<ll, ll> calc(ll tg){
    ll zcnt=0, ocnt=0;
    while(tg){
        if(tg%2) ocnt++;
        else zcnt++;
        tg /=2;
    }
    return {zcnt, ocnt};
}


ll findIdx(ll tg){
    
}


/*
현재 수보다 크고, 비트가 1~2개 다르면 바로 정답에 넣고 종료

비트 판정
    현재수의 비트를 탐색하면서, 0인 곳이 있으면
        해당 비트를 1로 바꾸고, 정답 처리 후 종료
    없다면
        현재수의 비트보다 큰 하나의 비트를 찾고
        그외에는 0인 값을 정답에 넣기
        

현재 수의 최상위 비트의 위치와, 탐색수의 최상위 비트 위치
차이만큼 0의 개수 늘리기
*/
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    ll mx = 1000000000000000;
    for(auto num : numbers){
//        비트 판정
        if(num ==0){
            answer.push_back(1);
            continue;
        }
        
        for(ll i = num+1; i<=mx; i++){
            ll diff =0;
            ll tmp =i;
            ll brt =num;
            //비트 탐색
           while(tmp){
                ll b1   = tmp%2;
                ll b2   = brt%2;
                if(b1!=b2) diff++;
               
               if(diff>2) break;
               tmp/=2;
               brt/=2;
           }
            if(diff >2 )continue; //조건 만족하는 수 나올때까지 탐색
            answer.push_back(i);
            break;
        }
        
        
    }
    
    
   
    return answer;
}




/*
0 1 1 1 1
1 0 1 1 1

*/