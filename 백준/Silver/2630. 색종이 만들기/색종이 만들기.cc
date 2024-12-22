#include <bits/stdc++.h>
using namespace std;

int board[150][150];
int num[2];
bool checkBoard(int n, int r, int c){
    int tmp=board[r][c];
    for(int i=r; i<n+r; i++){
        for(int j=c; j<n+c; j++){
            if(tmp != board[i][j])
                return false;
        }
    }
    return true;
}

void solve(int n, int r, int c){
    if(checkBoard(n,r,c)){
        num[board[r][c]]++;
        return ;
    }
    int paper=n/2;
    for (int i = 0; i < 2; i++)
    {
        for(int j=0; j<2; j++){
            solve(paper,r+i*paper,c+j*paper);
        }
    }
    
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for (int  i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>board[i][j];
        }
    }

    solve(n,0,0);
    cout<<num[0]<<"\n"<<num[1];
}