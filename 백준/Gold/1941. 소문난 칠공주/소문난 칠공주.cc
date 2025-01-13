#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string s[5];
bool visit[5][5];
bool isused[25];
int ans,dasom;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


// bfs 툴
pair<int, int>group[7];
bool g_visit[7];

bool check_group(){
    fill(g_visit,g_visit+7,0);
    queue<int> q;
    g_visit[0]=1;
    q.push(0);
    while (!q.empty())
    {
        auto cur=q.front(); q.pop();
        int cur_x=group[cur].X;
        int cur_y=group[cur].Y;

        for (int i = 0; i < 4; i++)
        {
            int nx=cur_x+dx[i];
            int ny=cur_y+dy[i];
            if(nx<0 || nx>4 || ny<0 || ny>4) continue;
            for (int nxt = 0; nxt < 7; nxt++)
            {
                if(g_visit[nxt])continue;
                if(group[nxt].X==nx && group[nxt].Y==ny){
                    g_visit[nxt]=1;
                    q.push(nxt);
                }
            }
            
        }
        

    }
    for(auto c:g_visit){
        if(!c) return false;
    }
    return true;

}



void solve(int t, int cur){
    if(t==7){
        if(dasom>=4 && check_group()){
            ans++;
        }
        return;
    }
    for (int i = cur; i < 25; i++)
    {
        int x=i/5;
        int y=i%5;
        if(isused[i]) continue;
        isused[i]=1;
        group[t].X=x; group[t].Y=y;
        if(s[x][y]=='S') dasom++;
        solve(t+1,i+1);
        isused[i]=0;
        if(s[x][y]=='S') dasom--;

    }
    


}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
    {
        cin>>s[i];
    }
    solve(0,0);
    cout<<ans;
    
}