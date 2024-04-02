#include<bits/stdc++.h>
using namespace std;

int board1[25][25];
int board2[25][25];
int n, ans;

void rotate(){
    int temp[25][25]={};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j]=board2[n-1-j][i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board2[i][j]=temp[i][j];
}

void tilt(int dir){
    while (dir--) rotate();
    
    for (int i = 0; i < n; i++)
    {
        int tild[25]={};
        int idx=0;
        for (int j = 0; j < n; j++)
        {
            if(board2[i][j]==0) continue;
            if(tild[idx]==0)
                tild[idx]=board2[i][j];
            else if(tild[idx]==board2[i][j])
                tild[idx++]*=2;
            else
                tild[++idx]=board2[i][j];

        }
        for (int j = 0; j < n; j++)
            board2[i][j]=tild[j];
    }
}

void solve(int t){
    if(t==5){
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans=max(ans, board2[i][j]);
        return;                    
    }
    for (int dir = 0; dir < 4; dir++)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans=max(ans, board2[i][j]);
    }
    

}