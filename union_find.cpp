#include <bits/stdc++.h>
<<<<<<< HEAD

using namespace std;


// vector<int> adj[200];
// int p[200];

// int find(int x){
//     if(p[x]<0){
//         return x;
//     }

//     p[x] = find(p[x]);
// }


// bool uni(int u , int v){
//     u = find(u);
//     v = find(v);

//     if(u==v) return false;

//     if(p[v] < p[u]) // v의 랭크가 더 높은 경우
//         swap(u,v);

//     if(p[v] == p[u])
//     p[u]--;
//     p[v] =u;

//     return true;

// }


vector<int> adj[200];
int p[200];

int find(int x){
    if(p[x] < 0 ) return x;
    return p[x] = find(p[x]);
}


bool uni(int u, v){
    u =find(u);
    v =find(v);


    if(u ==v) 
    return false;
    if(p[v] < p[u]) // 
