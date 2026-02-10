
#include <bits/stdc++.h>
using namespace std;

/*
  2
4 1 3
  5
  6

명령에 따라 굴리고 지도칸이 0이면 주사위 -> 지도
아니면 지도 -> 주사위 ,칸은 0으로
*/
int dice[7];
int brd[25][25];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0}; // 동서북남
int n, m, k, x, y;

int idx[5][4] = {
    {},
    {4, 1, 3, 6}, // 동
    {4, 6, 3, 1}, // 서
    {2, 6, 5, 1}, // 북
    {2, 1, 5, 6}  // 남
};

void roll(int dir)
{
    int nx = x + dx[dir - 1];
    int ny = y + dy[dir - 1];

    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
        return;

    x = nx;
    y = ny;

    int tmp[7];
    for (int i = 0; i < 7; i++)
        tmp[i] = dice[i];

    for (int i = 0; i < 4; i++)
        tmp[idx[dir][(i + 1) % 4]] = dice[idx[dir][i]];

    for (int i = 0; i < 7; i++)
        dice[i] = tmp[i];

    // 지도가 0이면
    if (brd[x][y] == 0)
    {
        brd[x][y] = dice[6];
    }
    else
    {
        dice[6] = brd[x][y];
        brd[x][y] = 0;
    }
    cout << dice[1] << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> brd[i][j];
        }
    }

    while (k--)
    {
        int dir;
        cin >> dir;

        roll(dir);
    }
}