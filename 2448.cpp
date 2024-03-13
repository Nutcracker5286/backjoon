#include<bits/stdc++.h>
using namespace std;

string board[23000];

void solve(int n, int r, int c){
    if(n==3){
        board[r][c+2]='*';
        board[r+1][c+1]='*';
        board[r+1][c+3]='*';
        for (int i = 0; i < 5; i++)
        {
            board[r+2][c+i]='*';
        }
        return;
    }
    int nxt=n/2;
    solve(nxt, r, c+nxt);
    solve(nxt, r+nxt, c);
    solve(nxt, r+nxt, c+n);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    
    for (int i = 0; i < n; i++)
    {
        board[i]=string((n/3*5+n/3-1),' ');
    }
    solve(n,0,0);
    for (int i = 0; i < n; i++)
    {
        cout<<board[i]<<'\n';
    }
    
    
}