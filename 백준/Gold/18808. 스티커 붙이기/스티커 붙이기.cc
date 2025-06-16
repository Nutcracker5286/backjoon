#include <bits/stdc++.h>
using namespace std;

int n,m,k,r,c,px,py;
int ans;
int board[50][50];
int sticker[15][15];


// 각 방향마다 호출 되어 스티커 붙일 수 있는 지 확인
bool isPs(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i+r>n || j+c>m)  continue;
            bool passStage=false;
            for(int row=0; row < r; row++){
                if(passStage) break;
                for(int col=0; col<c; col++){
                    if(board[i+row][j+col]==1 && sticker[row][col]==1){
                        passStage=true;
                        break;
                    }
                }
            }
            if(passStage) continue;
            px=i; py = j;

            return 1;
        }
    }
    return 0;
}


// 90도 회전
void rotateSt(){
    int tmp[15][15]={0};
    for(int i=0; i<c; i++){
        queue<int> Q;

        for(int j=r-1; j>=0; j--){
            Q.push(sticker[j][i]);
        }

        for(int j=0; j<r; j++){
            if(Q.empty()) break;
            tmp[i][j]=Q.front(); Q.pop();
        }
    }
    swap(r,c);

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            sticker[i][j]=tmp[i][j];
        }
    }
}

// 스티커 붙이기
void paste(int x, int y){
    for(int i=x; i<x+r; i++){
        for(int j=y; j<y+c; j++){
            if(board[i][j]==1) continue;
            board[i][j]=sticker[i-x][j-y];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>k;
    int a=k;
    while(a--){
        for(int i=0; i<15; i++)
            fill(sticker[i],sticker[i]+15,0);

        cin>>r>>c;
        
        
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                cin>>sticker[i][j];
        
        for(int d=0; d<4; d++){
            if(!isPs()) {
                rotateSt();
                
                continue;
            }
            paste(px,py);

            break;
        }
    }


    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            ans+=board[i][j]!=0;
  
    cout<<ans;
}

 