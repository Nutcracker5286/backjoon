#include <bits/stdc++.h>
using namespace std;

/*
물고기 m마리 존재 , 초기 상어 크기 2, 1초에 상하좌우 한칸 이동 가능
같거나 작은 칸만 이동 가능, 같은칸은 섭취 불가, 큰 칸은 이동 불가

먹을 수 있는 물고기 1마리면 그거 먹으러
1마리 이상이면 거리 가까운 (이동칸의 최솟값)
최소 거리가 여러마리면 가장 위쪽,  여러마리면 왼쪽에 있는 물고기

이동과 동시에 섭취
크기와 같은수의 섭취시 크기 1증가

더이상 먹을 수 있는 물고기 없으면 종료

입력 받기
고기 리스트에 추가

게임 시작
현재 상어와 리스트에 있는, 먹을 수 있는  고기와의 거리 계산 및 1순위 선정
해당 물고기 없다면 게임 종료
이동과 동시에 섭취,이동 칸수 만큼 초 초과
*/
int brd[25][25];
vector<pair<int, int>> f;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, sx, sy, cnt, sz;

// 상어와 해당 좌표의 물고기와의 거리 계산
int calc(int tx, int ty)
{
    int vis[25][25];
    fill(&vis[0][0], &vis[0][0] + 625, -1);

    queue<pair<int, int>> q;
    vis[sx][sy] = 0;
    q.push({sx, sy});

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if (vis[nx][ny] != -1)
                continue;
            if (brd[nx][ny] > sz)
                continue;
            if (nx == tx && ny == ty)
            {
                return vis[x][y] + 1;
            }
            vis[nx][ny] = vis[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> brd[i][j];
            if (brd[i][j] == 9)
            {
                sx = i;
                sy = j;
                sz = 2;
            }
            else if (brd[i][j] != 0)
                f.push_back({i, j});
        }
    }

    // gaME 시작
    int ans = 0;
    while (1)
    {
        // 현재 상어의 위치 토대로 1순위 먹이 선정
        deque<tuple<int, int, int>> rank; // 순위, 좌표
        for (auto [x, y] : f)
        {
            if (brd[x][y] >= sz || brd[x][y] == 0)
                continue; // 먹이 제외
            int dist = calc(x, y);
            if (dist == -1)
                continue;
            if (rank.empty())
            {
                rank.push_front({dist, x, y});
                continue;
            }

            auto [a, b, c] = rank.front();
            // 거리 계산 후 랭크앞에 있는 값보다 작으면 앞에
            if (dist < a)
                rank.push_front({dist, x, y});
            else if (dist == a)
            {
                // 더 위에 있다면 물고기 삽입
                if (b > x)
                {
                    rank.push_front({dist, x, y});
                }
                // 이것도 같다면 더 왼쪽 물고기 삽입
                else if (b == x)
                {
                    if (c > y)
                    {
                        rank.push_front({dist, x, y});
                    }
                }
            }
        }

        // 먹이가 없다면 종료
        if (rank.empty())
        {
            cout << ans;
            return 0;
        }

        // 이동 및 시간 계산 , 사이즈 및 횟수 갱신
        auto [d, x, y] = rank.front();
        brd[sx][sy] = 0;
        ans += d;
        sx = x;
        sy = y;
        brd[x][y] = 0;
        cnt++;
        if (cnt == sz)
        {
            sz++;
            cnt = 0;
        }
    }
    cout << ans;
}
