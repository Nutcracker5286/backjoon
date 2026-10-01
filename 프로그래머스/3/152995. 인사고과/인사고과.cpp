#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

/*
근태 + 동평 점수 = 원점수
원점수에 따른 석차 계산하여  완호의 석차 구하기

1.
특정인원 근태 < 모든 인원 근태 &&  동평 < 모든 동평이면 
    석차 제외

2.  
나머지 인원들은 원점수로 석차 편입, 동점이면 동석차에 건너뛰기
정렬 시키고 석차 출력


pq 시간 초과

따라서 정렬
하나 고정 테크닉
근태 기준 내림차 정렬하고
동평 기준 오름차해서 
이전 최대 동평보다 최대값보다 작으면 불가
    완호랑 같으면 -1 반환
총점이 완호보다 높으면 랭크업


*/


int solution(vector<vector<int>> scores) {
    int sc1 = scores[0][0], sc2 = scores[0][1];
    int wanscr =  sc1+sc2;
    
    sort(scores.begin(),scores.end(), [](auto a ,auto b){
        if(a[0] == b[0])
            return  a[1] < b[1];
        return a[0] > b[0];
    });
    
        

    int rank=1;
    int mx=0;
    for(auto  v :  scores){
        if(v[1] < mx){
            if( v[0] == sc1 && v[1] == sc2)
                return -1;
        }
        else{
            mx= v[1];
            if(v[0]+v[1] > wanscr){
                rank++;
            }
        }
    }
    
    
    
    
    
    return rank;
}