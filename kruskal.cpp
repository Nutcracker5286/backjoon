#include <bits/stdc++.h>
<<<<<<< HEAD

using namespace std;


vector<int> adj[200];
int p[200];

int find(int x){
    if(p[x]<0){
        return x;
    }

    return p[x] = find(p[x]);
}


bool uni(int u , int v){
    u = find(u);
    v = find(v);

    if(u==v) return false;

    if(p[v] < p[u]) // v의 랭크가 더 높은 경우
        swap(u,v);

    if(p[v] == p[u])
    p[u]--;
    p[v] =u;

    return true;

}

vector<tuple<int,int,int>> eg ; // cost, sv ,ev
int v,e;
void kruskal(){
    sort(eg.begin(), sg.end());
    int cnt =0;
    for(int i=0; i<eg.size(); i++){
        auto [cost, sv, ev] = eg[i];

        if(!uni(sv,ev)) continue; // 유니온 불가시 패스
        cnt++;
        if(cnt == v-1) return;
    }

    
