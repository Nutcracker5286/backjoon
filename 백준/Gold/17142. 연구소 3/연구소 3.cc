#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

/*
전체 바이러스 중에 m개만 선택해서 활성화
활성화 된것만 전파 가능
모든 빈카에 바이러스를 퍼뜨리는 최소 시간 구하기

m개 선택, bfs 활용해서 전파
비활된거가 만나면 활성화 처리

완료 후 전체 빈칸 체크
시간 갱신

모든경우에 전체 빈칸 체크 불가능 시 -1 출력
*/

int brd[55][55];
int vis[55][55];
int n, m, ans = INT_MAX;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> virus;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> brd[i][j];
            if (brd[i][j] == 2)
                virus.push_back({i, j});
        }
    }

    // mask 생성
    vector<int> mask(virus.size() - m, 0);
    for (int i = 0; i < m; i++)
        mask.push_back(1);

    // 조합 시작
    bool imp = 1;
    do
    {
        fill(&vis[0][0], &vis[0][0] + 55 * 55, -1); // 방문배열 초기화

        queue<pair<int, int>> q;
        for (int i = 0; i < mask.size(); i++)
        {
            if (mask[i] == 0)
                continue;
            q.push({virus[i]});
            vis[virus[i].X][virus[i].Y] = 0;
        }

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;
                if (vis[nx][ny] != -1)
                    continue;
                if (brd[nx][ny] == 1)
                    continue;

                vis[nx][ny] = vis[x][y] + 1;
                q.push({nx, ny});
            }
        }

        // 모두 전파 체크 및 최대값 갱신
        int ts = 0;
        bool allchk = 1;
        for (int i = 0; i < n; i++)
        {
            if (!allchk)
            { // 전파안되엇으면 종료
                break;
            }
            for (int j = 0; j < n; j++)
            {
                if (brd[i][j] != 0)
                    continue; // 빈칸만 고려
                if (vis[i][j] == -1)
                { // 빈칸이고 방문하지 않았으면
                    allchk = 0;
                    break;
                }
                else
                {
                    ts = max(ts, vis[i][j]);
                }
            }
        }

        if (allchk)
        {
            ans = min(ans, ts);
            imp = 0;
        }

    } while ((next_permutation(mask.begin(), mask.end())));
    cout << (!imp ? ans : -1);
}