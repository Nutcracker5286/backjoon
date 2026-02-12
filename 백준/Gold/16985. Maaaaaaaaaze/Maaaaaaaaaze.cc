/*
5개의 판 존재하고 합쳐서 정육면체의 미로 구성
구성 후에 최단 탈출 경로 구하기

각 판을 회전 가능, 각 판을 임의로 배치 가능

각판이 가능한 경우의 수 * 각 판을 배치하는 경우의 수
1024*120*125 1천5백만

회전 함수 구현
방향은 4진수 조합으로 구현
배치는 순열로 구현

배치가 끌날때까지 진행
각 판의 방향 결정 후 회전
8개의 꼭짓점 중 하나 선택해서 시작점 반대 방향에 위치한 곳이 탈출로 설정하고
시작점을 넣고 bfs 시행, 시행후에 탈출로가 미방문이면 패스 방문했으면 최솟값 비교 후 갱신

정답 출력
*/
#include <bits/stdc++.h>
using namespace std;

int brd[5][5][5];
// 시물레이션용 판
int tmp[5][5][5];
int maze[5][5][5];
int vis[5][5][5];
int rot[5];
int ans = 1000000;
vector<int> mask = {0, 1, 2, 3, 4};
int idx[4][3] = {
    {0, 0, 0},
    {0, 0, 4},
    {0, 4, 0},
    {0, 4, 4},
};
bool isImp = 1;
int dz[6] = {1, -1, 0, 0, 0, 0};
int dx[6] = {0, 0, 1, 0, -1, 0};
int dy[6] = {0, 0, 0, 1, 0, -1};

// num 판을 90도만큼 회전 시키는 함수
void roll(int num)
{
    int nxt[5][5];
    for (int i = 0; i < 5; i++)
    { // 전환전의 열
        for (int j = 0; j < 5; j++)
        { // 전환전의 행
            nxt[i][j] = tmp[num][5 - 1 - j][i];
        }
    }
    for (int i = 0; i < 5; i++)
    { // 전환전의 열
        for (int j = 0; j < 5; j++)
        { // 전환전의 행
            tmp[num][i][j] = nxt[i][j];
        }
    }
}

// 000,004,040,044
void bfs(int cokidx)
{
    auto [z, x, y] = idx[cokidx];
    if (maze[z][x][y] == 0)
    { // 진입 불가 시 종료
        return;
    }
    int ez = 4 - z;
    int ex = 4 - x;
    int ey = 4 - y;
    if (maze[ez][ex][ey] == 0)
    { // 탈출 불가 시 종료
        return;
    }
    // 방문배열 초기화
    for (int k = 0; k < 5; k++)
    {
        for (int i = 0; i < 5; i++)
            fill(vis[k][i], vis[k][i] + 5, 0);
    }

    queue<tuple<int, int, int>> q;
    q.push({z, x, y});
    vis[z][x][y] = 1;

    while (!q.empty())
    {
        auto [a, b, c] = q.front();
        q.pop();
        for (int d = 0; d < 6; d++)
        {
            int nz = a + dz[d];
            int nx = b + dx[d];
            int ny = c + dy[d];
            if (nz < 0 || nx < 0 || ny < 0 || nz >= 5 || nx >= 5 || ny >= 5)
                continue;
            if (vis[nz][nx][ny] != 0)
                continue;
            if (maze[nz][nx][ny] == 0)
                continue;
            vis[nz][nx][ny] = vis[a][b][c] + 1;
            q.push({nz, nx, ny});
        }
    }
    if (vis[ez][ex][ey] == 0)
        return;
    ans = min(ans, vis[ez][ex][ey]);
    isImp = 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 판 입력
    for (int k = 0; k < 5; k++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> brd[k][i][j];
            }
        }
    }

    // 판 배치 시작
    do
    {

        // 회전 조합 생성
        for (int comp = 0; comp < (1 << 10); comp++)
        {
            int brute = comp;
            for (int k = 0; k < 5; k++)
            {
                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        tmp[k][i][j] = brd[k][i][j];
                    }
                }
            }
            // 각판마다 회전 진행
            for (int r = 0; r < 5; r++)
            {
                rot[r] = brute % 4;
                brute /= 4;
                while (rot[r]--)
                    roll(r);
            }

            // 흩어진 판 조합 하기
            for (int k = 0; k < 5; k++)
            {
                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        maze[k][i][j] = tmp[mask[k]][i][j];
                    }
                }
            }

            // 4개의 꼭짓점 중 하나 선택
            vector<int> cok = {0, 0, 0, 1};
            // 000,004,040,044
            do
            {
                for (int i = 0; i < 4; i++)
                {
                    if (cok[i])
                    {
                        // 탈출시에는 최단 경로 갱신도 하는 bfs 진행
                        bfs(i);
                    }
                }
            } while (next_permutation(cok.begin(), cok.end()));
        }

    } while (next_permutation(mask.begin(), mask.end()));

    if (isImp)
    {
        cout << -1;
        return 0;
    }
    cout << ans - 1;
}
