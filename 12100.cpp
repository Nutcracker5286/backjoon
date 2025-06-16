#include<bits/stdc++.h>
using namespace std;

int board[25][25];
int board2[25][25];
bool issum[25][25];
int n,ans;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void rotate(){
    int temp[25][25];

    for(int i=0; i<n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j]=board2[n-1-j][i];
    for(int i=0; i<n; i++)
        for (int j = 0; j < n; j++)
            board2[i][j]=temp[i][j];
    // 가로 세로 바꾸기 but n*n배열이라 해당 없음   
}

void tiltld(int dir){
    while (dir--) rotate();
   for (int i = 0; i < n; i++)
   {
        int tild[21]={};
        int idx=0;
        for (int j = 0; j < n; j++)
        {
            if(board2[i][j]==0) continue;
            if(tild[idx]==0){
                tild[idx]=board2[i][j];
                continue;
            }
            else if(board2[i][j]==tild[idx])
                tild[idx++]*=2;
            else
                tild[++idx]=board2[i][j];
        }
        for (int j = 0; j < n; j++)
            board2[i][j]=tild[j];
   }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>board[i][j];
            ans=max(ans,board[i][j]);
        }
        
    }
    for (int tmp = 0; tmp < (1<<10); tmp++)
    {
        int brute=tmp;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board2[i][j]=board[i][j];

        for (int i = 0; i < 5; i++)
        {
            int dir=brute%4;
            brute/=4;
            tiltld(dir);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans=max(ans,board2[i][j]);
    }
    cout<<ans;
}