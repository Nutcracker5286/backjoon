#include <bits/stdc++.h>
#define X first
#define Y second
using namespace;

const int INF = 0x3f3f3f3f;
int d[200];
vector<pair<int,int>> adj[200]; //비용, 정점 번호


int v,e,st;

/*
우선 순위 큐를 이용한 다익스트라 알고리즘

1. 우선 순위 큐에 시작점 추가
2. 우선 순위 큐에서 가장 작은 원소 선택
    해당거리가 최단 거리 테이블에 있는 값과 다를 경우 
        3번 과정을 수행하지 않고 넘어감
3. 원소가 가리키는 정점을 v라고 할 때
    v와 이웃한 정점들에 대해 최단거리 테이블 값보다 v를 경유하는것이 더 작은값을 가질 경우
        최단거리 테이블의 값을 갱신하고 우선 순위 큐에 (거리, 이웃 정점 번호) 추가
4. 우선 순위 큐가 빌때까지 2,3번 과정 반복
*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>v>>e>>st;
    fill(d,d+v+1,INF);

    while(e--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }

    priority_queue<pair<int,int>>,
     vector<pair<int,int>>,
     greater<pair<int,int>>> pq; // cost , 시작 , 끝

    d[st] = 0;
    

    // 우선 순위 큐에 (0,시작점) 추가
    while(!pq.empty()){
        auto [cost, a]


    }


}