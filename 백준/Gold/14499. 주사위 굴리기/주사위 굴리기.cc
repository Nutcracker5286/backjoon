#include <bits/stdc++.h>
using namespace std;
/*
주사위 굴리기
맵의 숫자에 따라 주사위의 상태가 변한다.
주사위 이동시마다 상단 값 출력
*/
int n,m,x,y,k;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

int map_[21][21];
int dice[4][3];

void roll(int dir, int curX, int curY){
    int temp[4][3]={};
    for(int i=0;i<4;i++)
        for(int j=0;j<3;j++)
            temp[i][j]=dice[i][j];
    dir--;
    int nx=curX+dx[dir];
    int ny=curY+dy[dir];
    if(nx<0 || nx>=n || ny<0 || ny>=m) return;
    x=nx; y=ny;
    //주사위 굴리기
    if(dir==0){//동
        dice[1][0]=temp[3][1];
        dice[1][1]=temp[1][0];
        dice[1][2]=temp[1][1];
        dice[3][1]=temp[1][2];
    }
    else if(dir==1){//서
        dice[1][0]=temp[1][1];
        dice[1][1]=temp[1][2];
        dice[1][2]=temp[3][1];
        dice[3][1]=temp[1][0];
    }
    else if(dir==2){//북
        dice[0][1]=temp[1][1];
        dice[1][1]=temp[2][1];
        dice[2][1]=temp[3][1];
        dice[3][1]=temp[0][1];

    }
    else{//남
        dice[0][1]=temp[3][1];
        dice[1][1]=temp[0][1];
        dice[2][1]=temp[1][1];
        dice[3][1]=temp[2][1];
    }

    //이동한 칸이 0이면 주사위 바닥면이 칸에 복사
    if(map_[nx][ny]==0){
        map_[nx][ny]=dice[3][1];
    }
    else{
        dice[3][1]=map_[nx][ny];
        map_[nx][ny]=0;
    }
    cout<<dice[1][1]<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>x>>y>>k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>map_[i][j];
    for(int i=0;i<k;i++){
        int dir;
        cin>>dir;
        roll(dir,x,y);
    }
}