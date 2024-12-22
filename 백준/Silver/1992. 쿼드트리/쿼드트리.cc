#include <bits/stdc++.h>
using namespace std;

string board[200];

bool checkBoard(int n, int r ,int c){
    for(int i=r; i<r+n; i++){
        for(int j=c; j<c+n; j++){
            if(board[r][c]!=board[i][j])
            return false;
        }
    }
    return true;
}

void solve(int n, int r, int c){
    if(checkBoard(n,r,c)){
        cout<<board[r][c];
        return ;
    }
    int zipSize=n/2;
    cout<<"(";
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            solve(zipSize,r+i*zipSize,c+j*zipSize);
        }
    }
    cout<<")";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>board[i];
    }
    solve(n,0,0);
}