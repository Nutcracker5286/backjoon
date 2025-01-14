#include <bits/stdc++.h>
using namespace std;

pair<int, int> ansGroup[7];
int ansCnt;
string board[5];
bool vis[5][5];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

// 연결성과 다솜 개수 확인
bool chkCondition(){
    queue<pair<int, int>> Q;
    Q.push(ansGroup[0]);
    bool temp[5][5]={0};
    int ds;
    if(board[ansGroup[0].first][ansGroup[0].second]=='S')
        ds=1;
    else
        ds=0;
    int cnt=1;
    temp[ansGroup[0].first][ansGroup[0].second]=1;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir =0; dir<4; dir++){
            int nx=cur.first+dx[dir];
            int ny=cur.second+dy[dir];
            if(nx<0 || nx>4 || ny<0 || ny>4 ) continue;
            if(temp[nx][ny] ||!vis[nx][ny]) continue;
            if(board[nx][ny]=='S') ds++;
            cnt++;
            temp[nx][ny]=1;
            Q.push({nx,ny});
        }
    }

    return cnt == 7 && ds>=4;
}

void solve(int k, int st){
    if(k==7){
        if(chkCondition()){
            ansCnt++;
        }
        return ;
    }
    for(int i=st; i<25; i++){
        int x=i/5;
        int y=i%5;
        ansGroup[k]={x,y};
        vis[x][y]=1;
        solve(k+1, i+1);
        vis[x][y]=0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i =0; i<5 ; i++)
    cin>>board[i];

    solve(0,0);
    cout<<ansCnt;
}