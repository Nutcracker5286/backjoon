#include <string>
#include <bits/stdc++.h>
using namespace std;


/*
0 ~ 10 이 경계 시작 위치 5,5
인접행렬로 그래프 표현 방문 표시로 1 미방문 0
순회해서 1인 곳 서치
*/
int brd[55][55][55][55];

bool oob(int x, int y){
    return x<0 || y<0 || x>10 || y>10;
}


int solution(string dirs) {
    int ans = 0;
    int sx=5, sy=5,nx=5,ny=5;
    brd[5][5][5][5]=1;

    
    
    for(auto cmd : dirs){
        if(cmd == 'U'){
            if(oob(sx-1,sy)) continue;
            if(!brd[sx][sy][sx-1][sy]){
                brd[sx][sy][sx-1][sy]=1;
                brd[sx-1][sy][sx][sy]=1;
                ans++;
            }
            sx--;

        }
        else if(cmd == 'D'){
            if(oob(sx+1,sy)) continue;
            if(!brd[sx][sy][sx+1][sy]){
                brd[sx][sy][sx+1][sy]=1;
                brd[sx+1][sy][sx][sy]=1;
                ans++;
            }
            sx++;
        }
        else if(cmd == 'R'){
            if(oob(sx,sy+1)) continue;
            if(!brd[sx][sy][sx][sy+1]){
                brd[sx][sy][sx][sy+1]=1;
                brd[sx][sy+1][sx][sy]=1;
                ans++;
            }
            sy++;
        }
        else if(cmd == 'L'){
            if(oob(sx,sy-1)) continue;
            if(!brd[sx][sy][sx][sy-1]){
                brd[sx][sy][sx][sy-1]=1;
                brd[sx][sy-1][sx][sy]=1;
                ans++;
            }
            sy--;
        }
    }    
    
    int cnt =0;
    for(int i=0; i<=10; i++){
        for(int j=0; j<=10; j++){
            for(int k=0; k<=10; k++)
                for(int t=0; t<=10; t++)
            cnt+=brd[i][j][k][t]==1;
        }
        cout<<'\n';
    }
    
    return ans;
}