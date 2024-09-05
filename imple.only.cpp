#include <bits/stdc++.h>
using namespace std;

int board[100][100];
bool visit[100][100];
int dx[4] = {1, 0 - 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;
    visit[0][0] = 1;
    Q.push({0,0});

    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = cur.first+dx[i]; 
            int y = cur.second+dy[i]; 
            if(x<0 || x>100 || y<0 || y>100) continue;
            if(visit[x][y]) continue;
            visit[x][y]=1;
            Q.push({x,y});
        }

        

    }
    

}