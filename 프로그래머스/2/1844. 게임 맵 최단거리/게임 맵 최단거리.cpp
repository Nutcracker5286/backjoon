#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] ={0,1,0,-1};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int vis[110][110] = {};
    int n  =  maps.size();
    int m = maps[0].size();
    queue<pair<int,int>> q;
    
    q.push({0,0});
    vis[0][0]=1;
    
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        
        for(int d=0; d<4; d++){
            int nx = x+dx[d] , ny =y+dy[d];
            if(nx< 0 || ny< 0 || nx>=n || ny>= m) continue;
            if(maps[nx][ny]==0) continue;
            if(vis[nx][ny]!=0) continue;
            q.push({nx,ny});
            vis[nx][ny] = vis[x][y]+1;
        }
    }
    
    
    
    return vis[n-1][m-1] == 0 ? -1 : vis[n-1][m-1] ;
}