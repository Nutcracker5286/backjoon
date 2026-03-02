#include <bits/stdc++.h>
using namespace std;

/*
n 바이 m 행렬에서 통로 3개를 뽑아 벽으로 변경한뒤
바이러스를 전파시키고 안전 영역의 최대값 구하기

0~n*m를 0으로 초기화 하고 뒤에 세개 빼고 3개는 1 추가 해서 np로 조합
뽑힌 곳의 x좌표는 m의 몫, y좌표는 나머지
벽으로 변경하고 시행
*/

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m, ans;
int vis[10][10];
int brd[10][10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    vector<pair<int, int>> vi;
    vector<pair<int, int>> gr;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> brd[i][j];

            if (brd[i][j] == 2)
            {
                vi.push_back({i, j});
                vis[i][j] = 1;
            }
            if (brd[i][j] == 0)
            {
                gr.push_back({i, j});
            }
        }
    }

    vector<int> mask(gr.size() - 3, 0);
    for (int i = 0; i < 3; i++)
        mask.push_back(1);

    // 선택 조합 시작
    do
    {
        // 시뮬레이션 보드 및, 방문 배열, 큐 생성
        int tmp[15][15], vis2[15][15];
        queue<pair<int, int>> virus;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                tmp[i][j] = brd[i][j];
                vis2[i][j] = vis[i][j];
            }
        }

        for (int i = 0; i < vi.size(); i++)
            virus.push(vi[i]);

        // 뽑은 곳 벽으로변경
        for (int i = 0; i < gr.size(); i++)
        {
            if (mask[i])
            {
                auto [x, y] = gr[i];
                tmp[x][y] = 1;
            }
        }

        while (!virus.empty())
        {
            auto [x, y] = virus.front();
            virus.pop();

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if (tmp[nx][ny] != 0)
                    continue;
                if (vis2[nx][ny] != 0)
                    continue;
                vis2[nx][ny] = 1;
                tmp[nx][ny] = 2;
                virus.push({nx, ny});
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (tmp[i][j] == 0)
                    sum++;
            }
        }
        ans = max(sum, ans);

    } while (next_permutation(mask.begin(), mask.end()));
    cout << ans;
}