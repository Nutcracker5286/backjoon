#include <bits/stdc++.h>
using namespace std;

/*
bfs로 연합 가능조건을 충족하는 나라 탐색하여 연합 형성하기
인구이동 년수 업
더이상 인구이동이 일어나지 않는다면 종료
=>
*/

int brd[55][55];
int n, l, r;
int vis[55][55];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool oob(int x, int y)
{
    return x < 0 || y < 0 || x >= n || y >= n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> brd[i][j];
        }
    }

    int year = 0;
    bool ismove = 1;
    do
    {
        // 초기화
        for (int i = 0; i < n; i++)
            fill(vis[i], vis[i] + n, 0);

        // 전체 탐색하며 연합 가능성 탐색
        int num = 1;
        vector<pair<int, int>> con[2510];
        int psum[2510] = {0};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (vis[i][j] != 0)
                    continue; // 이미 연합 했으면 패스

                queue<pair<int, int>> q;
                vis[i][j] = num;
                q.push({i, j});
                con[num].push_back({i, j});
                psum[num] += brd[i][j];

                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++)
                    {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (oob(nx, ny))
                            continue;
                        if (vis[nx][ny] != 0)
                            continue;
                        // 연합 형성 조건
                        int dif = abs(brd[nx][ny] - brd[x][y]);
                        if (dif < l || dif > r)
                            continue;
                        vis[nx][ny] = num;
                        q.push({nx, ny});
                        con[num].push_back({nx, ny});
                        psum[num] += brd[nx][ny];
                    }
                }
                num++;
            }
        }

        // 연합 표시된곳을 연합 인구수로 조정
        ismove = 0;
        for (int i = 1; i < num; i++)
        {
            int score = psum[i] / con[i].size();
            for (auto [x, y] : con[i])
            {
                if (brd[x][y] != score)
                { // 달라서 이동한 경우
                    ismove = 1;
                    brd[x][y] = score;
                }
            }
        }

        if (ismove)
            year++;

    } while (ismove);
    cout << year;
}