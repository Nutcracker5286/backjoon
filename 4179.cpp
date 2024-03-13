#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

// 불
int dist_1[1002][1002];
// 지훈
int dist_2[1002][1002];

int main()
{
    int R, C;
    cin >> R >> C;
    string board[1001];
    queue<pair<int, int>> Q;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    for (int i = 0; i < R; i++)
    {
        fill(dist_1[i], dist_1[i] + C, -1);
        fill(dist_2[i], dist_2[i] + C, -1);
    }

    for (int i = 0; i < R; i++)
    {
        cin >> board[i];
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (board[i][j] == 'F')
            {
                Q.push({i, j});
                dist_1[i][j] = 0;
            }
        }
    }

    while (!Q.empty())
    { // 불의 전파 시간 구하기
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                continue;
            if (dist_1[nx][ny] >= 0 || board[nx][ny]=='#')
                continue;
            dist_1[nx][ny] = dist_1[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (board[i][j] == 'J')
            {
                Q.push({i, j});
                dist_2[i][j] = 0;
            }
        }
    }
    while (!Q.empty())
    { // 지훈이 탈출 시간
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
            {
                // 미로를 탈출하므로 종료
                cout << dist_2[cur.X][cur.Y] + 1;
                return 0;
            }
            // 갔던 곳이거나 벽이면 다음 차레
            if (dist_2[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            // 불인 곳이고 지훈이가 도달하는 시간이 불 전파 시간보다 길면 다음 차레
            if (dist_1[nx][ny] != -1 && dist_1[nx][ny] <= dist_2[cur.X][cur.Y] +1)
                continue;
            dist_2[nx][ny] = dist_2[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    // 탈출 못하면 불가능
    cout << "IMPOSSIBLE";
}