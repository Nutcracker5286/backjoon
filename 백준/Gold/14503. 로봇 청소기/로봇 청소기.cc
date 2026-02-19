#include <bits/stdc++.h>
using namespace std;

int brd[55][55];
int vis[55][55];

int n, m, r, c, d;

// 북동남서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool oob(int nx, int ny)
{
    return nx < 0 || ny < 0 || nx >= n || ny >= m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r >> c >> d;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> brd[i][j];
        }
    }

    int sx = r;
    int sy = c;
    int ans = 0;
    while (true)
    {
        if (!vis[sx][sy])
        {
            vis[sx][sy] = 1; // 현재 칸 청소
            ans++;
        }

        // 주변 4칸 탐색
        bool isNone = 0;

        for (int i = 0; i < 4; i++)
        {
            int nx = sx + dx[i];
            int ny = sy + dy[i];
            if (oob(nx, ny))
                continue;
            if (brd[nx][ny] || vis[nx][ny])
                continue;
            // 청소되진 않은 빈칸이 있는 경우
            isNone = 1;
            break;
        }

        // 미청소, 빈칸
        if (isNone)
        {
            while (1)
            {
                d = (d + 3) % 4; // 반시계 회전
                int nx = sx + dx[d];
                int ny = sy + dy[d];
                if (oob(nx, ny))
                    continue;
                if (vis[nx][ny] || brd[nx][ny])
                    continue;
                sx = nx;
                sy = ny;
                break;
            }
        }
        else
        {
            int nx = sx - dx[d];
            int ny = sy - dy[d];
            if (oob(nx, ny) || brd[nx][ny])
            {
                cout << ans;
                return 0;
            }
            sx = nx;
            sy = ny;
        }
    }
}