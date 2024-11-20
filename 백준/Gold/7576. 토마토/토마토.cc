
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
    int board[1001][1001];
    int dist[1001][1001];


int main()
{
    int n, m;
    cin >> m >> n;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            if (t == 1)
                Q.push({i, j});
            if (t == 0)
                dist[i][j] = -1;
            board[i][j] = t;
        }
    }

    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny] != -1)
                continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    int ans=0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(dist[i][j]==-1){
                cout<<-1;
                return 0;

            }
            ans=max(ans,dist[i][j]);
        }
    }

    cout<<ans;
}