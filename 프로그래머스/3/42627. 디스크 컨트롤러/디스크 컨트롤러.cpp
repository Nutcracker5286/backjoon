#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
/*
대기 큐 = 소요시간 short, 요청시간 fast, 작업 번호 small

컨트롤러  =  작업 x and 대기 큐 not empty
=> 대기 큐에서 꺼내서 해당 작업 시행, 작업 끝낼때까지 진행

작업 마감 , 요쳥 시간 동일시 큐에 저장후에 꺼냄


소요시간 짧은걸로 정렬

현재 완료 개수  < 작업 개수 반복

    현재 시간보다 작으면
        작업 반복 삽입

    대기 큐가 비면
        그냥 작업 시키고, 갱신
    대기 큐가 비어있지 않으면
        큐에서 꺼내서 작업 시키고, 갱신
    


*/
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    // 요청시간 짧은걸로 정렬
    sort(jobs.begin(),jobs.end()); //요청, 소요
    
    //소요, 요청, 작업
    priority_queue <tuple<int,int,int>, vector<tuple<int,int,int>>,
     greater<tuple<int,int,int>> > pq;
    
    
    
    int n = jobs.size();
    //현재 작업개수, 현재 시간, 총 시간
    int cnt =0,curT =0,  tot=0 ,idx = 0;
// 현재 완료 개수  < 작업 개수 반복
    while(cnt <n){
    // 현재 시간보다 작으면
        // 작업 반복 삽입
        while( idx< n &&  jobs[idx][0]<=curT){
            pq.push({jobs[idx][1], jobs[idx][0],idx++});
        }
        
    // 대기 큐가 비면
        if(pq.empty()){
    //     그냥 다음 요청 시간으로 
            curT =  jobs[idx][0];
        }
        else{
                    cnt++;

    // 대기 큐가 비어있지 않으면
    //     큐에서 꺼내서 작업 시키고, 갱신
            int a,b,c ;
            tie(a,b,c) = pq.top(); pq.pop();
            curT +=a;
            tot += curT  - b;
        }
         
    }

    return tot/n;
}