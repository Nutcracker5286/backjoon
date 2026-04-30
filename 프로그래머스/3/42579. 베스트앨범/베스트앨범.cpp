#include <bits/stdc++.h>


/*
각 장르별 조회수로 정렬, 가장 조회수가 높은 장르부터 탐색 시작
장르별로 가장 많은 조회수 2곡만 답에 삽입
*/
using namespace std;

// 장르명,조회수 내림차 고유번호 오름차
bool cmp(tuple<string,int,int> a, tuple<string,int,int> b){
    auto [g1,t1,i1] = a;
    auto [g2,t2,i2] = b;

    if(g1==g2){
        if(t1==t2){
            return i1<i2;
        }
        else
            return t1>t2;
    }
    else
        return g1>g2;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m;
    vector<tuple<string,int,int>> rk; // 장르명, 조회수,고유번호
    vector<pair<int,string>> gr; // 총조회수 , 장르명
    
    // 장르별로 조회수 취합
    for(int i=0; i< plays.size(); i++){
        m[genres[i]]+=plays[i];
        rk.push_back({genres[i],plays[i],i});
    }
    // 총조회수, 장르명
    for(auto [k,v]: m){
        gr.push_back({v,k});
    }
    //개별로 장르명, 조회수, 내림차 고유번호 순으로 오름차
    sort(rk.begin(),rk.end(),cmp);
    
    //총조회수, 장르면 정렬
    sort(gr.begin(),gr.end(),greater<pair<int,string>>{});
    
    //총조회수가 많은 장르부터
    for(auto [t,g] :gr){
        // 장르가 일치하면 거기서 순위 매겨진 2곡 추가
        int cnt =0;
        for(auto [ge,cn,id] :rk){
            if(g!=ge) continue;
            if(cnt<2){
                answer.push_back(id);
                cnt++;
            }
        }        
    }
    
    
    
    
    return answer;
}