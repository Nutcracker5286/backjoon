#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[53][53];
int vis[53][53];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, N, M, K;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int cnt = 0;
        cin >> M >> N >> K;
        for (int j = 0; j < N; j++)
        { // 테스트 케이스 마다 보드 및 방문 초기화
            fill(board[j], board[j] + M, 0);
            fill(vis[j], vis[j] + M, 0);
        }
        queue<pair<int, int>> Q;
        for (int j = 0; j < K; j++)
        {
            int a, b;
            cin >> a >> b;
            board[b][a] = 1;
        }

        for (int j = 0; j < N; j++)
        {
            for (int z = 0; z < M; z++)
            {
                if (board[j][z] != 1 || vis[j][z] == 1)
                    continue;
                cnt++;
                Q.push({j, z});
                vis[j][z] = 1;
                while (!Q.empty())
                {
                    auto cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                            continue;
                        if (vis[nx][ny] == 1 || board[nx][ny] != 1)
                            continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        cout << cnt << "\n";


    }

    return 0;
}