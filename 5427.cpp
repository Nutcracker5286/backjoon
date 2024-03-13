#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int dist_f[1002][1002];
int dist_s[1002][1002];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while (t--)
    {
        int w,h;
        bool run=false;
        cin>>w>>h;

        string board[1002];
        queue<pair<int ,int>> Q_f;
        queue<pair<int ,int>> Q_s;
        for (int i = 0; i < h; i++)
        {
            cin>>board[i];
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                // 상근
                if(board[i][j]=='@'){ Q_s.push({i,j}); dist_s[i][j]=1;}
                // 불
                if(board[i][j]=='*'){ Q_f.push({i,j}); dist_f[i][j]=1;}
            }
        }
        
        // 불에 대한 전파시간 구하기
        while (!Q_f.empty())
        {
            auto cur=Q_f.front(); Q_f.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx=cur.X+dx[i];
                int ny=cur.Y+dy[i];
                if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
                if(dist_f[nx][ny]!=0 || board[nx][ny]=='#') continue;
                dist_f[nx][ny]=dist_f[cur.X][cur.Y]+1;
                Q_f.push({nx,ny});
            }
        }

        while ((!Q_s.empty()) && (!run))
        {
            auto cur=Q_s.front(); Q_s.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx=cur.X+dx[i];
                int ny=cur.Y+dy[i];
                if(nx<0 || nx>=h || ny<0 || ny>=w){
                    cout<<dist_s[cur.X][cur.Y]<<"\n"; run=true; break;
                }
                if(dist_s[nx][ny]!=0 || board[nx][ny]=='#') continue;
                if(dist_f[nx][ny]!=0 && dist_f[nx][ny]<=dist_s[cur.X][cur.Y]+1) continue;
                dist_s[nx][ny]=dist_s[cur.X][cur.Y]+1;
                Q_s.push({nx,ny});
            }
        }

        if(!run) cout<<"IMPOSSIBLE\n";

        for (int i = 0; i < h; i++)
        {
            fill(dist_f[i], dist_f[i]+w,0);
            fill(dist_s[i], dist_s[i]+w,0);
        }
        
        
        
    }
    
}