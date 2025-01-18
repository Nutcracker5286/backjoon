#include <bits/stdc++.h>
using namespace std;

pair<int, int> cctv[10];
int n,m,wall, camCnt;
int ans=10000;

int vis[10][10];
int maze[10][10];

void camFill(int x, int y, int d, bool isUpd){
    int i= d==0 || d==3?1:-1;

    switch(d){
        case 0: //우
            while(1){
                if(y+i>=m) return;
                if(maze[x][y+i]==6) return;
                if(maze[x][y+i]!=0){
                    i++;
                    continue;
                }
                isUpd?vis[x][y+i]++:vis[x][y+i]--;
                i++;
            }
        break;

        case 2: //좌
            while(1){
                if(y+i<0) return;
                if(maze[x][y+i]==6) return;
                if(maze[x][y+i]!=0){
                    i--;
                    continue;
                }
                isUpd?vis[x][y+i]++:vis[x][y+i]--;
                i--;
            }
        break;

        case 1: //상
            while(1){
                if(x+i<0) return;
                if(maze[x+i][y]==6) return;
                if(maze[x+i][y]!=0){
                    i--;
                    continue;
                }
                isUpd?vis[x+i][y]++:vis[x+i][y]--;
                i--;
            }
        break;

        case 3: //하
            while(1){
                if(x+i>=n) return;
                if(maze[x+i][y]==6) return;
                if(maze[x+i][y]!=0){
                    i++;
                    continue;
                }
                isUpd?vis[x+i][y]++:vis[x+i][y]--;
                i++;
            }
        break;
    }
}

void solve(int k){
    if(k==camCnt){
        int cnt=0;
        for(int i=0; i<n;i++)
            for(int j=0; j<m; j++)
                cnt+=vis[i][j]==0;
        
        ans=min(ans,cnt);


        return;
    }
    int x=cctv[k].first;
    int y=cctv[k].second;
    int camNum=maze[x][y];
    switch(camNum){
        case 1:
        for(int d=0; d<4; d++){
            camFill(x, y, d, 1);
            solve(k+1);
            camFill(x, y, d, 0);
        }
        break;

        case 2:
        for(int d=0; d<2; d++){
            camFill(x, y, d, 1);
            camFill(x, y, d+2, 1);
            solve(k+1);
            camFill(x, y, d, 0);
            camFill(x, y, d+2, 0);
        }
        break;

        case 3:
        for(int d=0; d<4; d++){
            camFill(x, y, d, 1);
            camFill(x, y, (d+1)%4, 1);
            solve(k+1);
            camFill(x, y, d, 0);
            camFill(x, y, (d+1)%4, 0);
        }
        break;

        case 4:
        for(int d=0; d<4; d++){
            camFill(x, y, d, 1);
            camFill(x, y, (d+1)%4, 1);
            camFill(x, y, (d+2)%4, 1);
            solve(k+1);
            camFill(x, y, d, 0);
            camFill(x, y, (d+1)%4, 0);
            camFill(x, y, (d+2)%4, 0);
        }
        break;
        
        case 5:
        for(int d=0; d<4; d++)
            camFill(x, y, d, 1);
        solve(k+1);
        break;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int t=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>maze[i][j];
            if(maze[i][j]==6) {
                wall++;
                vis[i][j]=-1;
            }
            else if(maze[i][j]!=0 && maze[i][j]!=6){
                camCnt++;
                cctv[t++]={i,j};
                vis[i][j]=-1;
            }
        }
    }        

   solve(0);
   cout<<ans;
}