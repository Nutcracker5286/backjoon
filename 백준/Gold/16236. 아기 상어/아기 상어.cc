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
1순위 먹이 선정
먹이가 없다면 게임 종료
섭취 후 사이즈 갱신
*/
int brd[25][25];
vector<pair<int, int>> f;
int dx[4] = {-1, 0, 1, 0}; // 위 왼
int dy[4] = {0, -1, 0, 1};
int n, sx, sy, cnt, sz;
int vis[25][25];

// 1순위 먹이 반납 ,거리 기준, x작은 기준, y 작은 기준
//  거리, 좌표
tuple<int, int, int> findFish()
{
    fill(&vis[0][0], &vis[0][0] + 625, -1);
    queue<pair<int, int>> q;
    tuple<int, int, int> st = {INT_MAX, INT_MAX, INT_MAX};
    q.push({sx, sy});
    vis[sx][sy] = 0;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (vis[x][y] >= get<0>(st))
            break;
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if (vis[nx][ny] != -1)
                continue;
            if (brd[nx][ny] > sz)
                continue;
            if (brd[nx][ny] != 0 && brd[nx][ny] < sz)
            { // 먹이 가능 후보 발견시 갱신
                st = min(st, {vis[x][y] + 1, nx, ny});
            }
            vis[nx][ny] = vis[x][y] + 1;
            q.push({nx, ny});
        }
    }

    return st;
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
                brd[i][j] = 0;
            }
        }
    }

    // gaME 시작
    int ans = 0;
    while (1)
    {
        // 1순위 먹이 선정
        auto [d, x, y] = findFish();
        // 먹이가 없다면 종료
        if (d == INT_MAX)
        {
            cout << ans;
            return 0;
        }

        brd[x][y] = 0;
        sx = x, sy = y;
        ans += d;
        cnt++;
        // 있다면 사이즈 갱신
        if (cnt == sz)
        {
            cnt = 0;
            sz++;
        }
    }
    cout << ans;
}