#include <bits/stdc++.h>
using namespace std;

/*
t초 후에 남아있는 미세먼지의 양 구하기

시뮬레이션
미세먼지가 확산된다
    미세먼지 존재 모든 칸에 인접한 4방향 확산
    인접 방향에 공청기가 있거나 경계 벗어나면 제외
    /5만 확산, 남는양은 -방향 개수 * /5
공청기 작동
    위쪽은 반시계방향 순환
    아래는 시계방향 순환
    바람 불면 방향 대로 모두 한칸씩 이동,공청기에 들어가면 미세먼지 삭제

보드에 먼지들 저장 탐색하면서 큐에서 확산
*/
int brd[55][55];
int vis[55][55];

int r, c, t, idx;
pair<int, int> ac[2];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> dust;

void dust_move()
{
    int tmp[110][110] = {};
    for (int i = 0; i < 2; i++)
    {
        auto [x, y] = ac[i];
        tmp[x][y] = -1;
    }
    // 미세먼지 모든 칸에서 증가, 시물용 판에서 욞긴후 원본 판에 재삽입
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (brd[i][j] == 0 || brd[i][j] == -1)
                continue;

            // 사방 검사
            int share = brd[i][j] / 5;
            int cnt = 0;
            for (int d = 0; d < 4; d++)
            {
                int nx = i + dx[d], ny = j + dy[d];
                if (nx < 0 || ny < 0 || nx >= r || ny >= c)
                    continue;
                if (brd[nx][ny] == -1)
                    continue;
                cnt++;
                tmp[nx][ny] += share;
            }
            // 확산 후 원본 양 줄어들음
            tmp[i][j] += (brd[i][j] - cnt * share);
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            brd[i][j] = tmp[i][j];
        }
    }
}

void air_work()
{
    int tmp[110][110] = {};
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            tmp[i][j] = brd[i][j];
        }
    }
    for (int i = 0; i < 2; i++)
    {
        auto [x, y] = ac[i];
        tmp[x][y] = -1;
    }

    // 위쪽은 반시계 순환 , 동 북 서 남
    auto [cx, cy] = ac[0];
    cy++;
    tmp[cx][cy] = 0;
    while (cy + 1 < c)
    { // 동
        tmp[cx][cy + 1] = brd[cx][cy];
        cy++;
    }

    // 북
    while (cx - 1 >= 0)
    {
        tmp[cx - 1][cy] = brd[cx][cy];
        cx--;
    }
    // 서
    while (cy - 1 >= 0)
    {
        tmp[cx][cy - 1] = brd[cx][cy];
        cy--;
    }

    // 남
    while (brd[cx + 1][cy] != -1)
    {
        tmp[cx + 1][cy] = brd[cx][cy];
        cx++;
    }

    // 아래는 시계방향 순환
    tie(cx, cy) = ac[1];
    cy++;
    tmp[cx][cy] = 0;
    while (cy + 1 < c)
    { // 동
        tmp[cx][cy + 1] = brd[cx][cy];
        cy++;
    }

    // 남
    while (cx + 1 < r)
    {
        tmp[cx + 1][cy] = brd[cx][cy];
        cx++;
    }
    // 서
    while (cy - 1 >= 0)
    {
        tmp[cx][cy - 1] = brd[cx][cy];
        cy--;
    }
    // 북
    while (brd[cx - 1][cy] != -1)
    {
        tmp[cx - 1][cy] = brd[cx][cy];
        cx--;
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            brd[i][j] = tmp[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> t;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> brd[i][j];
            if (brd[i][j] == -1)
            {
                ac[idx++] = {i, j};
            }
            else if (brd[i][j] != 0)
                dust.push({i, j});
        }
    }
    idx--;
    sort(ac, ac + 2);

    // t초동안 시뮬
    while (t--)
    {
        // 미세 먼지 확산
        dust_move();
        // 공청기 작동
        air_work();
    }
    int ans = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (brd[i][j] != -1)
                ans += brd[i][j];
        }
    }

    cout << ans;
}