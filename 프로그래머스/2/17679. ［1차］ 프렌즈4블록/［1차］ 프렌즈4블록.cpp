#include <string>
#include <bits/stdc++.h>

using namespace std;
int r,c;
int vis[50][50];    
int ans;
vector<string> brd;

bool oob(int x, int y){
    return x<0 || y<0 || x>=r || y>=c ;
}

bool chk(int x, int y){
    char flag = brd[x][y];
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++){
            if(oob(x+i,y+j)) return false;
            if(brd[x+i][y+j]!= flag) return false;
        }
    }
    return true;
}

void topuyo(int x, int y){
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++){
            vis[x+i][y+j]=1;
        }
    }
}


void puyo(){
    for(int i=0 ; i< c; i++){
        int row = r-1;
        for(int j=r-1; j>=0; j--){
            if(vis[j][i]) {
                ans++;
                brd[j][i]='*';
                continue;
            }
            char tmp = brd[j][i];
            brd[j][i]='*';
            brd[row--][i]= tmp;
            
        }
    }
}


/*
뿌요 문제와 유사
게임 시작

이차원 배열 탐색
     각 요소 시작으로 4칸 확인
        같은경우 지우기 마킹, 뿌요 성공 처리
뿌요 성공 못한경우
    정답값 출력
마킹된 부분 떨어 뜨리기


*/
int solution(int m, int n, vector<string> board) {
    r = m;
    c = n;
    brd =board;
    
    
    while(1){
        bool isPuyo =0;
        for(int i=0; i<r; i++)
            fill(vis[i],vis[i]+c,0);
        //보드 순회 약 900,백만번 이내로 최적화
        for(int i=0; i<r-1; i++){
            for(int j=0; j<c-1; j++){
                if( brd[i][j]=='*') continue; //부서진 곳 표시
                //현재 원소 기준 4칸 확인
                if(!chk(i,j)) continue;
                topuyo(i,j); //부술 칸 색칠하기
                isPuyo =1;
                
            }
        }
        
        //뿌요 못하면 종료
        if(!isPuyo) {
            
            for(auto c : brd){
                cout<<c<<'\n';
            }
            return ans;
        }
        
        // 터뜨리기 puyo
        puyo();
        
        
        
        
    }

}