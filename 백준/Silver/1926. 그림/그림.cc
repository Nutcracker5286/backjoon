#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4]={1,0,-1,0};
int dy[4]= {0,1,0,-1};

int board[501][501];
int vis[501][501];



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    int count = 0;
    int space = 0;

    cin>>n>>m;
    queue<pair<int,int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>board[i][j];
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(vis[i][j] || !board[i][j]) continue;
            
            count++;
            q.push({i,j});
            vis[i][j]=1;
            int tmp=1;

            while (!q.empty())
            {
                auto cur = q.front(); q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X+dx[dir];
                    int ny = cur.Y+dy[dir];
                    if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                    if (vis[nx][ny] || !board[nx][ny]) continue;
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                    tmp++;
                 }
            }
            space=max(space,tmp);
        }
        
    }

    cout<<count<<"\n"<<space;
    

}