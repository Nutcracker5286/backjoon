#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {1,-1,2,-2,2,-2,1,-1};
int dist[301][301];

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int len;
        cin>>len;

        for (int i = 0; i < len; i++)
        {
            fill(dist[i], dist[i]+len,-1);
        }
        int x,y, tar_x, tar_y;
        queue<pair<int, int>> Q;
        cin>>x>>y>>tar_x>>tar_y;
        Q.push({x,y});
        dist[x][y]=0;
        while (!Q.empty())
        {
            auto cur = Q.front(); Q.pop();
            for (int dir = 0; dir < 8; dir++)
            {
               int nx=cur.X+dx[dir];
               int ny=cur.Y+dy[dir];
               if(nx<0 || nx>=len || ny<0 || ny>=len) continue;
               if(dist[nx][ny]!=-1) continue;
               dist[nx][ny]=dist[cur.X][cur.Y]+1;
               Q.push({nx,ny});
            }
        }
        cout<<dist[tar_x][tar_y]<<"\n";
    }
    
}
