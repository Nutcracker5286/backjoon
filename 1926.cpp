#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main(){
    int n, m;
    cin>>n>>m;

    queue<pair<int, int>> Q;
    int dx[4]={1, 0,-1,0};
    int dy[4]={0 ,1, 0,-1};
    int board[501][501];
    int vis[501][501]={0};
    int max=0;
    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int t;
            cin>>t;
            if(t==1) board[i][j]=1;
            else board[i][j]=0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(vis[i][j] || board[i][j]!=1) continue;
            vis[i][j]=1;
            Q.push({i,j});
            int area=0;
            while(!Q.empty()){
                pair<int, int> cur =Q.front();
                Q.pop();
                area++;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx=cur.X+dx[dir];
                    int ny=cur.Y+dy[dir];
                    if(nx<0 || nx>=n || ny<0 || ny>m) continue;
                    if(vis[nx][ny] || board[nx][ny]!=1) continue;
                    vis[nx][ny]=1;
                    Q.push({nx,ny});
                }
            }
            cnt++;
            if(max<area) max=area;

        }
    }
    if(cnt==0) max=0;
    cout<<cnt<<"\n"<<max<<"\n";
    

}