#include <bits/stdc++.h>
using namespace std;

int board[2200][2200];
int num[3];

int boardCheck(int n, int r ,int c){
    int tmp = board[r][c];
    for(int i=r; i<n+r; i++){
        for(int j=c; j<n+c; j++){
            if(tmp != board[i][j]) return 100;
        }
    }
    return tmp;
}

void solve(int n, int r, int c){
    if(n==1){
        num[board[r][c]+1]++;
        return ;
    }

    int tmp =boardCheck(n,r,c);
    if(tmp != 100){
        num[tmp+1]++;
    }
    else{// 9개로 찢는 경우
        int paperSize=n/3;
        solve(paperSize,r,c);
        solve(paperSize,r,c+paperSize);
        solve(paperSize,r,c+2*paperSize);
        
        solve(paperSize,r+paperSize,c);
        solve(paperSize,r+paperSize,c+paperSize);
        solve(paperSize,r+paperSize,c+2*paperSize);
        
        solve(paperSize,r+2*paperSize,c);
        solve(paperSize,r+2*paperSize,c+paperSize);
        solve(paperSize,r+2*paperSize,c+2*paperSize);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }
    solve(n,0,0);

    for(int i=0; i<3 ; i++){
        cout<<num[i]<<"\n";
    }
    return 0;
}