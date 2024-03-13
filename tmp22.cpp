#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[20][20];
int board_copy[10][10];
int n, m, ca_cnt, ans, area;
vector <pair<int, int>> cctv;
bool isused[10];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void check_board(pair<int, int> ca, int dir, bool flag){
    int x=ca.X; int y=ca.Y;
    while (1)
    {
        x+=dx[dir];
        y+=dy[dir];
        if(x<0 || x>=n || y<0 || y>=m) return;
        if(board[x][y]==6) return;
        if(flag){
            if(board[x][y]!=0) continue;
            board[x][y]=7;
        }
        else{
            if(board[x][y]!=0) continue;
            board[x][y]=0;
        }
    }
    
}

void solve(int t){
    if(t==ca_cnt){
        int nosee=0;
        cout<<'\n';
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(board[i][j]==0) nosee++;
                cout<<board[i][j]<<' ';
            }
            cout<<'\n';
        }
        cout<<'\n';
        ans=min(ans,nosee);
        return;
    }
    for (int i = 0; i < ca_cnt; i++)
    {
        if(isused[i]) continue;
        isused[i]=1;
        switch (board[cctv[i].X][cctv[i].Y])
        {
        case 1:
        //우 상 좌 하
            for (int dir = 0; dir < 4; dir++){
                check_board(cctv[i],dir,1);
                solve(t+1);
                check_board(cctv[i],dir,0);
                }
            break;
        case 2:
        // 좌우, 상하
            for(int dir=0; dir<2; dir++){
                check_board(cctv[i],dir,1);
                check_board(cctv[i],dir+2,1);
                solve(t+1);
                check_board(cctv[i],dir,0);
                check_board(cctv[i],dir+2,0);
            }
            break;
        case 3:
            //(0,1) (1,2) (2,3) (3,0);
            for (int dir = 0; dir < 4; dir++)
            {
                int tmp=(dir+1)%4;
                check_board(cctv[i],dir,1);
                check_board(cctv[i],tmp,1);
                solve(t+1);
                check_board(cctv[i],dir,0);
                check_board(cctv[i],tmp,0);
            }
            break;
        case 4:
            // 상 하 (0,2) 1 || 3
            for (int dir = 1; dir < 4; dir+=2)
            {
                check_board(cctv[i],0,1);
                check_board(cctv[i],2,1);
                check_board(cctv[i],dir,1);
                solve(t+1);
                check_board(cctv[i],0,0);
                check_board(cctv[i],2,0);
                check_board(cctv[i],dir,0);
            }
            break;
        case 5:
            for(int dir=0; dir<4; dir++)
                check_board(cctv[i],dir,1);
            solve(t+1);
            for(int dir=0; dir<4; dir++)
                check_board(cctv[i],dir,0);
            break;
        default:
            break;
        }
        isused[i]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int wall_cnt=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>board[i][j];
            if(board[i][j]!=6 && board[i][j]!=0){
                cctv.push_back({i,j}); ca_cnt++;
            }
            if(board[i][j]==0) ans++;
        }
    }
    solve(0);

    cout<<ans;
    
}
