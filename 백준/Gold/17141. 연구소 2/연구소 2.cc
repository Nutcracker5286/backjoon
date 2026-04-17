#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m,ems,ans =INT_MAX;
int brd[55][55];
int vis[55][55];
vector<pair<int,int>> vi;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>brd[i][j];
            if(brd[i][j]==2){
            vi.push_back({i,j});
            }
            if(brd[i][j]!=1) ems++;
        }
    }


    vector<int> mask(vi.size(),0);
    fill(mask.end()-m,mask.end(),1);
    ems-=m;
    

    do{
        fill(&vis[0][0],&vis[0][0]+55*55,-1);

        int cnt=0, time=0;
        queue<pair<int,int>> q;
        for(int i=0; i<mask.size(); i++){
            if(mask[i]==0) continue;
            q.push(vi[i]);
            vis[vi[i].X][vi[i].Y]=0;  
        }

        while(!q.empty()){
            auto [x,y] =q.front(); q.pop();

            for(int d=0; d<4; d++){
                int nx = x+dx[d], ny = y+dy[d];
                if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                if(vis[nx][ny]!=-1) continue;
                if(brd[nx][ny]==1) continue;
                time=vis[nx][ny]= vis[x][y]+1;
                q.push({nx,ny});
                cnt++;
            }

        }
        if(ems == cnt){
            ans=min(ans , time);
        }

    }while(next_permutation(mask.begin(),mask.end()));
    cout<<(ans==INT_MAX ?-1:ans);
}