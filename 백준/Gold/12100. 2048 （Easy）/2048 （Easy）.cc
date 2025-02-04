#include <bits/stdc++.h>
using namespace std;


int board[25][25];
int board2[25][25];
int n;


void tilt(){
    for(int i=0; i<n; i++){
        int arr[25]={};
        int idx=0;
        for(int j=0; j<n; j++){
            if(board2[i][j]==0) continue;
            if(arr[idx]==0)
                arr[idx]=board2[i][j];
            else if(arr[idx]==board2[i][j])
                arr[idx++]*=2;
            else
                arr[++idx]=board2[i][j];
        }
        for(int j=0; j<n; j++) board2[i][j]=arr[j];
    }

}

void rotate(){
    int tmp[25][25]={};

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            tmp[i][j]=board2[i][j];

    for(int x=0; x<n; x++)
        for(int y=0; y<n; y++)
            board2[x][y]=tmp[n-1-y][x];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    
    int ans=0;
    for(int i=0;i<n; i++)
        for(int j=0; j<n; j++)
            cin>>board[i][j];
    
    for(int tmp=0; tmp<1024; tmp++){
        int brute=tmp;
        for(int i=0;i<n; i++)
            for(int j=0; j<n; j++)
            board2[i][j]=board[i][j];

        for(int i=0; i<5; i++){
            int dir=brute%4;
            while(dir--)rotate();
            tilt();
            brute/=4;
        }

        for(int i=0;i<n; i++)
            for(int j=0; j<n; j++)
                ans=max(ans,board2[i][j]);
    }

    cout<<ans;
}