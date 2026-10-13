#include <string>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int vis[600][600];
vector<vector<int>> brd;
queue<pair<int,int>> tmp;
vector<vector<int>> cmd;
int id =1;
int bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y]=id;
    int n =brd.size();
    int m =brd[0].size();
    int cnt =1;
    tmp.push({x,y});
    while(!q.empty()){
        auto [cx,cy] = q.front(); q.pop();
        
        for(int d=0; d<4; d++){
             int nx = cx+dx[d], ny =cy+dy[d];
            
            if(nx< 0 || ny< 0 || nx>= n || ny>=m)
                continue;
            if(brd[nx][ny]!=1) continue;
            if(vis[nx][ny]) continue;
            vis[nx][ny]=id;
            q.push({nx,ny});
            cnt++;
            tmp.push({nx,ny});
        }
    }
    
    
    return cnt;
}

/*
각 열마다 시뮬레이션 진행
    열 탐색마다 방문 보드 초기화
    현재 탐색 크기 =0
    방문하지 않은,석유 만나면, bfs 시행 및 현탐크에 더하기 
    
    세로 방향 탐색 종류 후
    전체 최대값 갱신
*/
int solution(vector<vector<int>> land) {
    int answer = 0;
    brd= land;
    
    int n = land.size();
    int m = land[0].size();
    cmd.assign(n, vector<int>(m,0));
    
    
    for(int i=0; i< n; i++){
        for(int j=0; j<m; j++){
            //땅이고, 방문했으면 패스 
            if(land[i][j]!=1 ||  vis[i][j]) continue;
            int cnt = bfs(i,j);
            while(!tmp.empty()){
                auto[x,y] =tmp.front();
                cmd[x][y] =cnt;
                vis[x][y]= id;
                tmp.pop();
            }
            id++;
        }
    }
    
    for(int i=0; i< m; i++){
         int cnt  =0;
        int cur =0;
        // cout<< "\n========\n";
        map<int,int> vimap;
        for(int j=0; j<n; j++){
            if(land[j][i]!=1 || vimap[vis[j][i]]) continue;
             cnt+= cmd[j][i];
             vimap[vis[j][i]]=1;
        }
         answer =max(answer,cnt);
    }
    
    
    
    return answer;
}