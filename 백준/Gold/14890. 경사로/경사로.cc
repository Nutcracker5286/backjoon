#include <bits/stdc++.h>
using namespace std;

/*
n정방행렬에서 경사로를 배치 하여 일자로 지나길 수 있는 길의 개수 출력

경사로 가능한 조건
높이 차이가 1, 낮은 칸에 있어야 함
놓은 칸의 높이가 모두 같아야 하고 경사로 길이 L 만큼 연속되어야 함

불가 조건
놓은곳에 또 경사로
높이 차이가 1이 아님
낮은지점 칸의 높이가 모두 동일하지 않음
L개가 연속되지 않음
경사로가 범위를 벗어남

가로방향, 세로방향 확인 => 가로방향만 체크하고 90도 회전해서 세로를 가로로 확인
길이 맞다면 카운트
아니라면 경사로 배팅, 배팅 후에도 안된다면 패스
*/

int brd[110][110];
int vis[110][110];
int n, l, ans; // 경사로 높이 1, 가로 l
int dy = 1;

bool chk(int x, int y)
{
    int bf = brd[x][y - 1];
    // 높이 차 체크, 이미 경사로를 놓은곳
    if (abs(bf - brd[x][y]) != 1 || vis[x][y])
        return false;

    // 높 -> 낮
    if (bf > brd[x][y])
    {
        // 현 위치에서 한계단씩 놓으면서 체크
        int st = brd[x][y];
        vector<int> cor;
        for (int i = 0; i < l; i++)
        {
            if (y + i >= n || brd[x][y + i] != st)
            { // oob,높이
                return false;
            }
            cor.push_back(y + i);
        }
        // 경사로를 놓을 수 있으면 놓기
        while (!cor.empty())
        {
            vis[x][cor.back()] = 1;
            cor.pop_back();
        }
    }
    // 낮 -> 높
    else
    {
        // 현위치에서 뒤로가면서 체크
        vector<int> cor;
        int st = brd[x][y] - 1;

        for (int i = 1; i <= l; i++)
        {
            // oob, 이미 경사로가 놓인 부분이면
            if (y - i < 0 || vis[x][y - i] || brd[x][y - i] != st)
                return false;
            cor.push_back(y - i);
        }
        while (!cor.empty())
        {
            vis[x][cor.back()] = 1;
            cor.pop_back();
        }
    }
    return true;
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        // 해당 행이 길이 맞는지 확인
        bool isRoad = 1;
        int st = brd[i][0]; // 이전 탐색 지점
        for (int j = 1; j < n; j++)
        {
            if (st == brd[i][j] || vis[i][j])
                continue;

            else
            { // 다르다면 경사로를 놓을 수 있는지 확인하고 st 갱신
                if (!chk(i, j))
                {
                    isRoad = 0;
                    break;
                }
                st = brd[i][j];
            }
        }
        ans += isRoad == true;
    }
}

void rot()
{
    for (int i = 0; i < n; i++)
        fill(vis[i], vis[i] + n, 0);

    int tmp[110][110];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp[i][j] = brd[n - 1 - j][i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            swap(tmp[i][j], brd[i][j]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> brd[i][j];
        }
    }

    // 가로 방향 확인
    solve();
    // 90도 회전
    rot();
    // 다시 가로 방향 확인 (회전 전의 세로 방향)
    solve();
    cout << ans;
}