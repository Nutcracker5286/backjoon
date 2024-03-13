#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int dist[101][101];
    queue<pair<int, int>> Q;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        fill(dist[i], dist[i] + m, -1);
    }

    string maze[101];
    for (int i = 0; i < n; i++)
    {
        cin >> maze[i];
    }
    Q.push({0,0});
    dist[0][0]=0;
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (maze[nx][ny] != '1' || dist[nx][ny] != -1)
                continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    cout << dist[n - 1][m - 1] + 1;
}