#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int vis[51][51];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, m,n,k;
    cin>>t;

    for (int i = 0; i < t; i++)
    { // tc 받고
        cin>>m>>n>>k;
        int ans=0;
        queue<pair<int , int>> Q;
        for (int j = 0; j < n; j++)
            fill(vis[j],vis[j]+m,-1);
        
        for (int j = 0; j < k; j++)
        {
            int a,b;
            cin>>a>>b;
            vis[b][a]=0;
        }

        // 전체 탐색 및 bfs 시행
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if(vis[j][k]!=0) continue;
                ans++;
                Q.push({j,k});
                vis[j][k]=-1;
                while (!Q.empty())
                {
                    auto cur = Q.front();
                    Q.pop();
                    for (int d = 0; d < 4; d++)
                    {
                        int nx = cur.X + dx[d];
                        int ny = cur.Y + dy[d];
                        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                        if(vis[nx][ny]!=0) continue;
                        Q.push({nx,ny});
                        vis[nx][ny]=-1;
                    }
                    
                }
                
            }
            
        }
        cout<<ans<<"\n";
    }
}