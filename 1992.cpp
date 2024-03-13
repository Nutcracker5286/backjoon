#include<bits/stdc++.h>
using namespace std;

bool check(const vector<vector<int>>& a,int n, int r, int c){
    int comp=a[r][c];
    for (int i = r; i < r+n; i++)
    {
        for (int j = c; j < c+n; j++)
        {
            if(comp!=a[i][j]) return false;
        }
        
    }
    return true;
    
}
void solve(const vector<vector<int>>& a,int n, int r, int c){
    if(check(a,n,r,c)){
        cout<<a[r][c];
        return ;
    }
    int half=n/2;
            cout<<"(";

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            solve(a,half,r+i*half,c+j*half);
        }
    }
            cout<<")";

    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> board(n, vector<int>(n+1));
    string s[100];
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           if(s[i][j]=='1') board[i][j]=1;
           if(s[i][j]=='0') board[i][j]=0;
        }
        
    }
    
    solve(board,n,0,0);
    
}