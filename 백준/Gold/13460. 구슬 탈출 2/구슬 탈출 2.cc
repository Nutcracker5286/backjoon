#include <bits/stdc++.h>
using namespace std;

/*
구슬을 사방으로 굴려서 구멍으로 빨간 구슬만 빼는 게임
단순히 판을 기울이는 시물레이션 하면 복잡도 초과

동시에 영향을 주는 bfs로 진행, 기울이면 벽 또는 구멍까지 이동해야됨
따라서 4개의 좌표를 유지하는 4차원 bfs

빨강 이동, 벽이 아니거나 구멍에 빠지지 않을때까지
파랑 이동, 벽이 아니거나 구멍에 빠지지 않을때까지

파랑이 구멍에 빠졌으면 컨티뉴
빨강이 빠졋으면 출력 후 종료
이동 위치가 같으면 이동 거리 비교후에 긴쪽이 한거리 무르기  -> 더 늦게 이동했기 때문

*/
char brd[15][15];
int vis[15][15][15][15];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;

int rx, ry, bx, by;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> brd[i][j];
            if (brd[i][j] == 'R')
            {
                rx = i;
                ry = j;
            }
            else if (brd[i][j] == 'B')
            {
                bx = i;
                by = j;
            }
        }
    }

    queue<tuple<int, int, int, int>> q;
    vis[rx][ry][bx][by] = 1;
    q.push({rx, ry, bx, by});

    while (!q.empty())
    {
        auto [x, y, tx, ty] = q.front();
        q.pop();
        if (vis[x][y][tx][ty] > 10)
        {
            cout << -1;
            return 0;
        }
        for (int d = 0; d < 4; d++)
        {
            int nx = x;
            int ny = y;
            int mx = tx;
            int my = ty;
            int rDist = 0;
            int bDist = 0;
            // 빨강 이동 , 다음 칸이 벽이 아니면 전진
            while (brd[nx + dx[d]][ny + dy[d]] != '#' && brd[nx][ny] != 'O')
            {
                nx += dx[d];
                ny += dy[d];
                rDist++;
            }
            // 파랑 이동
            while (brd[mx + dx[d]][my + dy[d]] != '#' && brd[mx][my] != 'O')
            {
                mx += dx[d];
                my += dy[d];
                bDist++;
            }
            // 파랑이 구멍에 빠졋는지
            if (brd[mx][my] == 'O')
            {
                continue;
            }
            // 빨강이 구멍에 빠졋는지
            if (brd[nx][ny] == 'O')
            {
                cout << vis[x][y][tx][ty];
                return 0;
            }
            // 둘 다 동일 위치에 오는 경우, 거리 긴쪽을 덜 이동 시킴, 느리기 때문
            if (nx == mx && my == ny)
            {
                if (rDist < bDist)
                {
                    mx -= dx[d];
                    my -= dy[d];
                }
                else
                {
                    nx -= dx[d];
                    ny -= dy[d];
                }
            }

            // 방문 하지 않은 상태면 큐에 삽입
            if (vis[nx][ny][mx][my] == 0)
            {
                vis[nx][ny][mx][my] = vis[x][y][tx][ty] + 1;
                q.push({nx, ny, mx, my});
            }
        }
    }

    cout << -1;
}