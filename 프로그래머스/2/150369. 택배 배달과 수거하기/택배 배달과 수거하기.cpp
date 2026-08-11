#include <string>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
그리디, 투 포인터
가장 먼곳의 배달이나,수거부터 처리

가장 마지막 배달 인덱스 || 수거 인덱스가 0보다 크면 반복
    현재 가장 마지막으로 방문해야 하는 인덱스 체크
    배달적재량이 cap보다 작거나 인덱스가 0이면 종료
        적재량에 담기, 배달 인덱스 감소
    배달적재량이 cap보다 크면은
        배달 인덱스가 마지막 인덱스 후보
        차이를 현재 인덱스에 저장
    수거 인덱스가 cap보다 작거나 인덱스아 0이면 종료
        수거량에 담기, 수거 인덱스 감소
    수거량이 cap보다 크면은
        수가 인덱스가 마지막 인덱스 후보
        차이를 현재 인덱스에 저장
        
    정답에 2*라스트 더함
    마지막 인덱스 = 수거 배달 중 max
        

*/
ll min(ll a, ll b){
    return a<b ? a: b;
}

long long solution(int cap, int n, vector<int> dels, vector<int> picks) {
    long long answer = 0;
    
    ll lidx  =n-1, bidx =-1, ridx=-1;
    
    for(int i= n-1; i>=0; i--){
        if(dels[i]){
            bidx =i;
            break;
        }
    }

    for(int i= n-1; i>=0; i--){
        if(picks[i]){
            ridx =i;
            break;
        }
    }
    
    lidx =max(bidx,ridx);
    
//     가장 마지막 배달 인덱스 || 수거 인덱스가 0보다 크면 반복
    while(bidx >= 0 || ridx >= 0){
        ll bcnt =0, rcnt=0;
        
        //     배달적재량이 cap보다 작거나 인덱스가 0초과면 반복
        while(bidx >=0 && bcnt< cap){
            bcnt +=dels[bidx--];
        }
        
        //     배달적재량이 cap보다 크면은
        if(bcnt > cap){
            dels[++bidx] = bcnt -cap;
        }
        else{
            while(bidx>=0 && dels[bidx]==0){
                bidx--;
            }
        }
        //     수거적재량이 cap보다 작거나 인덱스가 0초과면 반복
        while(ridx >=0 && rcnt< cap){
            rcnt +=picks[ridx--];
        }
        
        //     수거적재량이 cap보다 크면은
        if(rcnt > cap){
            picks[++ridx] = rcnt -cap;
        }
        else{
            while(ridx>=0 && picks[ridx]==0) {
                ridx--;
            };
        }
        
        answer+=(lidx+1)*2;
        lidx = max(bidx, ridx);
    }

    
    
    return answer;
}