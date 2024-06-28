#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
/*
보드 순회
bfs 돌면서 cnt 4개 이상이면 지울 수 있는거
아니면 못 지움
*/
char field[12][6];
int isused[12][6];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ans;
bool isposs;

void change();


// 뿌요 확인 bff 순회, 4개 이상이면 뿌요를 지운다. 이하면 방문노드 초기화
void bfs(pair<int, int> sta, char target){
    // 방문 노드 초기화
    for (int i = 0; i < 12; i++)
        fill(isused[i],isused[i]+6,0);
         
    

        
    int cnt=0;
    queue<pair<int, int>> q;
    q.push(sta);
    isused[sta.X][sta.Y]++;
    cnt++;
    while (!q.empty())
    {
        auto cur=q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0 || nx>=12 || ny<0 || ny>=6) continue;
            if(isused[nx][ny] || field[nx][ny]!=target) continue;
            q.push({nx,ny});
            isused[nx][ny]=1;
            cnt++;
        }
        
    }
    //4개 이상 뿌요 지우기
    if(cnt>=4){
        isposs=true;
        change();
        // cout<<"----------------\n";
        // for (int i = 0; i < 12; i++)
        // {
        //     for (int j = 0; j < 6; j++)
        //     {
        //         cout<<field[i][j];
        //     }
        //     cout<<'\n';
        // }
        // cout<<"----------------\n";
    }
   
}


// 지운 뿌요를 .으로 바꾼다.
void change(){
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if(isused[i][j]){
                field[i][j]='.';
            }
        }
    }
}

// 보드 순회, 뿌요를 아래로 내린다.
void down(){
    queue<char> tmp;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 11; j>=0; j--)
            if(field[j][i]!='.')
                {tmp.push(field[j][i]); field[j][i]='.';}
        for (int j =11; j>=0; j--)
        {
            if(!tmp.empty()){
                field[j][i]=tmp.front();
                tmp.pop();
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //보드 입력
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin>>field[i][j];
        }
    }

    //반복 시작
    while (1)
    {
        //부술 뿌요가 있는지 확인
        bool flag = 0;

        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {   //뿌요가 있는지 확인
                if(field[i][j]!='.')
                    bfs({i,j},field[i][j]);
            }
        }
        
        if(isposs){
            down();
            ans++;
            isposs=false;
            flag=1;
        //     cout<<"뿌요!!"<<"----------------\n";
        // for (int i = 0; i < 12; i++)
        // {
        //     for (int j = 0; j < 6; j++)
        //     {
        //         cout<<field[i][j];
        //     }
        //     cout<<'\n';
        // }
        // cout<<"----------------\n";
        }
        if(!flag) break;
    }

    cout<<ans;
}