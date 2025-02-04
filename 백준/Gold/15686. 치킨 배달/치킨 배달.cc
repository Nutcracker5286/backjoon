#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
/*
치킨집 m개 골랏을때 치킨 거리가
가장 작아 지는 조합 찾기
각 치킨집과의 치킨 거리 구하는 함수

*/
int city[55][55];
int n,m, ans;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
bool issell[3000];


void solve(int t, int cur){
    if(t==m){
        int m_dist=0;
        for(auto h:house){
            int dist=100000;
            for (int i = 0; i < chicken.size(); i++)
            {
                if(!issell[i]) continue;
                dist=min(abs(chicken[i].X-h.X)+abs(chicken[i].Y-h.Y),dist);
            }
            m_dist+=dist;
        }
                
        ans=min(ans,m_dist);
        return;
    }
    for (int i = cur; i < chicken.size(); i++)
    {
        int dist=0;
        issell[i]=1;
        solve(t+1,i+1);
        issell[i]=0;
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>city[i][j];
            if(city[i][j]==1) house.push_back({i,j});
            if(city[i][j]==2) chicken.push_back({i,j});
        }
    }
    ans=99999999;
    solve(0,0);
    cout<<ans;
}

