#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int vis_1[101][101];
int vis_2[101][101];
int color[3]={-1,0,1};

int main(){
    int n;
    int cnt_1=0;
    int cnt_2=0;

    queue<pair<int, int>> Q;

    cin>>n;

    string tmp[101];
    for (int i = 0; i < n; i++)
    {
        cin>>tmp[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(tmp[i][j]=='R') board[i][j]=-1;
            else if(tmp[i][j]=='G') board[i][j]=0;
            else if(tmp[i][j]=='B') board[i][j]=1;

        }
        
    }

    for (auto col : color)
    {//정상
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                    if(board[i][j]!=col || vis_1[i][j]) continue;
                    Q.push({i,j});
                    vis_1[i][j]=1;
                    while (!Q.empty())
                    {
                        auto cur = Q.front(); Q.pop();
                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nx=cur.X+dx[dir];
                            int ny=cur.Y+dy[dir];
                            if(nx<0 || nx>=n || ny<0 ||ny>=n) continue;
                            if(board[nx][ny]!=col  || vis_1[nx][ny]) continue;
                            Q.push({nx,ny});
                            vis_1[nx][ny]=1;
                        }
                    }
                    cnt_1++;
                    
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tmp[i][j] == 'R' ||tmp[i][j] == 'G')
                board[i][j] = 0;
            else if (tmp[i][j] == 'B')
                board[i][j] = 1;
        }
    }

    for (auto col : {0,1})
    { // 색맹
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                
                if (board[i][j] != col || vis_2[i][j])
                        continue;
                Q.push({i, j});
                vis_2[i][j] = 1;
                while (!Q.empty())
                {
                    auto cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        if (board[nx][ny] != col ||vis_2[nx][ny])
                            continue;
                        Q.push({nx, ny});
                        vis_2[nx][ny] = 1;
                    }
                }
                cnt_2++;
            }
        }
    }
    cout<<cnt_1<<" "<<cnt_2;
}