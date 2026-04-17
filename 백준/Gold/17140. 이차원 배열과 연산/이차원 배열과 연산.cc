#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int brd[105][105];
int r, c, k, rs = 3, cs = 3;

// 전치 함수
void trs()
{
    int mx = max(rs, cs);
    for (int i = 1; i <= mx; i++)
    {
        for (int j = i + 1; j <= mx; j++)
        {
            swap(brd[i][j], brd[j][i]);
        }
    }
    swap(rs, cs);
}

// r연산 시행
void R()
{
    int mx = 0;
    for (int i = 1; i <= rs; i++)
    {
        int fr[105] = {};
        vector<pair<int, int>> v; // 횟수, 크기

        for (int j = 1; j <= cs; j++)
        {
            fr[brd[i][j]]++;
        }
        for (int j = 1; j <= 101; j++)
        { // 0은 제외
            if (fr[j] == 0)
                continue; // 등장한 수만 고려
            v.push_back({fr[j], j});
        }
        sort(v.begin(), v.end()); // 정렬

        // 배열 삽입
        int idx = 1;
        for (auto c : v)
        {
            if (idx > 100)
                break;
            brd[i][idx++] = c.Y;
            brd[i][idx++] = c.X;
        }
        mx = max(mx, idx-1);

        // 0으로 패딩
        fill(brd[i] + idx, brd[i] + 105, 0);
    }
    cs = mx;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> k;

    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
            cin >> brd[i][j];
    }

    // 100초가 넘어가거나 목표 조건 달성 시 종료
    int ans = 0;
    while (brd[r][c] != k && ans <= 100)
    {
        // 행열 사이즈 비교 후 전치
        bool isTr = 0;
        if (rs < cs)
        { // 열연산 진행 해야 하는경우 따라서 전치
            isTr = 1;
            trs();
        }
        R();
        if (isTr)
            trs();
        ans++;
    }
    cout << (ans > 100 ? -1 : ans);
}