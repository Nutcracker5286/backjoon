#include <bits/stdc++.h>
using namespace std;

int n, m, r, c, d;
int brd[55][55];
int vis[55][55];

// 북동 남서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r >> c >> d;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> brd[i][j];

    // 게임 시작
    int x = r;
    int y = c;
    int ans = 0;
    while (1)
    {
        bool isNone = 0;
        // 청소되지 않으면, 청소
        if (!vis[x][y])
        {
            ans++;
            vis[x][y] = 1;
        }

        // 사방 탐색
        for (int i = 0; i < 4; i++)
        {
            // 90도 반시계
            d = (d + 3) % 4;
            // 앞쪽이 청소되지 않은 빈칸이면 한 칸 전직
            // 문제 조건에서 모서리는 벽이라고 명시함
            if (!vis[x + dx[d]][y + dy[d]] && !brd[x + dx[d]][y + dy[d]])
            {
                x += dx[d];
                y += dy[d];
                isNone = 1;
                break;
            }
        }
        if (isNone)
        {
            continue;
        }
        // 청소되지 않은, 빈칸이 없는경우
        // 후진 시 벽이면
        if (brd[x - dx[d]][y - dy[d]])
        {
            cout << ans;
            return 0;
        }
        // 아니면 후진
        x -= dx[d];
        y -= dy[d];
    }
}