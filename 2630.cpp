#include<bits/stdc++.h>
using namespace std;

int cnt[2];

bool check(const vector<vector<int>> &a, int r, int c, int n){
    int comp=a[r][c];
    bool fl=true;
    for (int i = r; i < r+n; i++)
    {
        for (int j = c; j < c+n; j++)
        {
            if(comp!=a[i][j]) return false;
        }
    }
    return true;   
}

void solve(const vector<vector<int>>& a, int r, int c, int n){
    if(check(a,r,c,n)){
        cnt[a[r][c]]+=1;
        return;
    }
    int nxt=n/2;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            solve(a,r+i*nxt,c+j*nxt,nxt);
            
        }
        
    }   
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n+1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    solve(board, 0, 0, n);

    cout << cnt[0]<<'\n'<<cnt[1];

    return 0;
}