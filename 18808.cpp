#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int board[50][50];
int sticker[15][15];
int r, c;

/*
90도 회전 시 변화는 좌표 작성을 통해 추론 가능
a가 기존 배열, b가 회전 후 배열
b[x][y] = a[r-1-y][x]이다
*/
void rotate(){
    int temp[15][15];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            temp[i][j]=sticker[i][j];
     for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
            sticker[i][j]=temp[r-1-j][i];
    int tmp=c;
    c=r;
    r=tmp;
}

bool canstic(int x, int y){
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(board[x+i][y+j] == 1 && sticker[i][j]==1)
                return false;
        }
    }
    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(sticker[i][j]==1)
                board[x+i][y+j]=1;
        }
    }
    return true;
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>k;

    while (k--)
    {
        cin>>r>>c;
        // 스티커 붙이고
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin>>sticker[i][j];
            }  
        }
        
        for (int rot = 0; rot < 4; rot++)
        {
            bool escape=false;
            for (int i = 0; i <= n-r; i++)
            {
                if(escape) break;
                for (int j = 0; j <= m-c; j++)
                {
                    if(canstic(i,j)){
                        escape=true;
                        break;
                    }
                }
            }
            if(escape) break;
            rotate();
        }
        
    }
    int ans=0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(board[i][j]==1) ans++;
        }
        
    }
    cout<<ans;
}
