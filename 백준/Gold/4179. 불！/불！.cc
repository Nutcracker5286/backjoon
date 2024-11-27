#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int boardF[1002][1002];
int boardJ[1002][1002];



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue<pair<int, int>> QF;
    queue<pair<int, int>> QJ;
    string maze[1002];
    int r, c;

    cin>>r>>c;
    for (int i = 0; i < r; i++)
    {
        cin>>maze[i];
        fill(boardF[i],boardF[i]+c,-1);
        fill(boardJ[i],boardJ[i]+c,-1);
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(maze[i][j]=='F') {
                QF.push({i,j});
                boardF[i][j]=0;
                }
            if(maze[i][j]=='J') {
                QJ.push({i,j});
                boardJ[i][j]=0;
                }
        }
    }

    while (!QF.empty())
    {
        auto cur = QF.front();
        QF.pop();
        for(int i=0; i<4; i++){
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];
            if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
            if(maze[nx][ny]=='#' || boardF[nx][ny]!=-1) continue;
            boardF[nx][ny] = boardF[cur.X][cur.Y]+1;
            QF.push({nx,ny});
        }
    }

    while (!QJ.empty())
    {
        auto cur = QJ.front();
        QJ.pop();
        for(int i=0; i<4; i++){
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];
            if(nx<0 || ny<0 || nx>=r || ny>=c) {
                // 탈출
                cout<<boardJ[cur.X][cur.Y]+1;
                return 0;
            }
            // 벽이거나 방문했거나
            if(maze[nx][ny]=='#' || boardJ[nx][ny]!=-1) continue;
            // 불이 붙었고 불보다 늦게 도착한 경우
            if(boardF[nx][ny]!=-1 && boardF[nx][ny]<=boardJ[cur.X][cur.Y]+1 ) continue;
            boardJ[nx][ny] = boardJ[cur.X][cur.Y]+1;
            QJ.push({nx,ny});
        }
    }

    cout<<"IMPOSSIBLE";
    
    
    
}