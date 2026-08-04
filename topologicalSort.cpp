#include <bits/stdc++.h>

using namespace std;


vector<int> adj[200];
int indeg[200];

/*
indeg가 0인 노드 큐에 삽입
큐에서 꺼내서 정렬 결과 벡터에 삽입
꺼낸 노드와 연결된 모든 정점 탐색
    ind--
    만약 indeg가 0이면 큐에 넣기

정답 벡터 사이즈가 n이 아니면
    사이클이 형성된것
정답 벡터 리턴
*/

int v,e;
void TopoSort(){

    queue<int> q;
    vector<int> res;


    for(int i=0; i<v; i++){
        if(indeg[i]==0) q.push(i);
    }


    while(!q.empty()){
        int cur = q.front(); q.pop();
        res.push_back(cur);

        for(int nxt :  adj[cur]){
            indeg[nxt]--;
            if(indeg[nxt]==0) q.push(nxt);
        }
    }

    if(res.size()!= v){
        cout<<"cycle exists\n";
        return ;
    }
    
    cout<< "cpt topoSort";
}