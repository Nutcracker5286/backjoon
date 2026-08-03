#include <bitst/stdc++.h>
using namespace std;
#define X first
#define Y second


/*
1. 임의 정점을 선택해 mst에 추가, 해당 정점과 연결된 간선을 pq에 추가
2. pq top 조회
    해당 간선이 두 mst에 포함된 두정점 연결 시 패스
    mst에 있는 정점과 mst에 없는 정점 연결시
        새정점, 간선을 mst에 추가
        새정점과 연결된 간선을 pq에 추가

mst의 간선이 v-1이 될때까지 2로 진행

*/

int v,e;
vector<pair<int,int>> adj[200]; // cost, ev;
bool chk[200]; // i번째 정점이 최소 신장 트리에 속해 있는가 
int cnt; // 현재 선택된 간선의 수
prirority_queue<tuple<int,int,int>, vector<tuple<int,int,int>> , greater<tuple<int,int,int>>>
pq; // 비용, 시작(mst에 있는 정점), 연결된 정점


//임의 정점 선택 및 해당정점 연결 간선 pq에 추가
chk[1];
for(auto nxt : adj[1]){
    pq.push({nxt.X, 1, nxt.Y});
}

/*
pq에서 꺼낸 후
    첫 정점은 이미 mst에 연결
    두번째 정점이 mst에 연결되었는지 체크
        연결 시
            패스
        cnt++
        해당정점과 연결된 정점 탐색
        연결된 정점이면 패스
        pq에 추가

*/

while(cnt < v-1){
    auto [c,a,b] = pq.front(); pq.pop();
    if(chk[b]) continue;
    chk[b]=1;
    cnt++;
    for(auto nxt: adj[cur]){
        if(chk[nxt.Y]) continue;
        pq.push({nxt.X, b, nxt.Y});
    }
    
}


