#include <bits/stdc++.h>
using namespace std;

/*
가로선을 3개 이하로 선택하는 문제
가로선은 연속되거나 중복되면 안됨

base
모든 세로선이 사다리 타면 자기 자신으로 내려 오는지 확인
k가 3이 되면 종료

함수
k번째 선택했고 그 다음 가로선 선택하는 함수
*/

int brd[50][50]; // x,y가 1이면 x+1,y+1까지 가로선이란 표시

int n, m, h, a, b, ans = INT_MAX;

/*
모든 세로선이 사다리 타고 자기 자기 자신과 동일한 경우에만 참
*/
bool chk()
{
    for (int i = 0; i < n; i++)
    {
        int y = i;
        for (int j = 0; j < h; j++)
        {
            // 내가 가로선 시작지점
            if (brd[j][y])
            {
                y++;
            }
            // 이전이 가로선 시작지점
            else if (y - 1 >= 0 && brd[j][y - 1])
                y--;
        }
        if (y != i)
            return false;
    }
    return true;
}

void solve(int k, int st)
{
    if (chk())
    { // 자기 자신으로 내려오면, 조합이지만 개수가 정해지지 않아 가지 치기
        ans = min(ans, k);
        return;
    }
    if (k == 3)
    {
        return;
    }

    // 가능한 자리 선택
    for (int i = st; i < n * h; i++)
    {
        int x = i / n, y = i % n;
        if (y == n - 1)
            continue; // 최우측이면 선택 불가
        if (brd[x][y])
            continue; // 이미 가로선이면 패스
        if (y - 1 >= 0 && brd[x][y - 1])
            continue; // 이전이 가로선이면 패스
        if (y + 1 < n - 1 && brd[x][y + 1])
            continue; // 다음이 가로선이면 패스
        brd[x][y] = 1;
        solve(k + 1, i + 1);
        brd[x][y] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;

    while (m--)
    {
        cin >> a >> b;
        brd[a - 1][b - 1] = 1;
    }

    solve(0, 0);
    ans > 3 ? cout << -1 : cout << ans;
}