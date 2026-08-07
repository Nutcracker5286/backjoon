
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m, hcnt;
vector<vector<int>> brd;
vector<vector<int>> vis;

bool oob(int x, int y)
{
    return x < 0 || y < 0 || x >= n || y >= n;
}

// 현재 위치 기준, 반지름 k일때 포함하는 순이익 계산
int calc(int x, int y, int k)
{ // 3 3 3
    hcnt = 0;

    for (int i = -k + 1; i <= k - 1; i++)
    { // -2  2
        for (int j = -k + 1; j <= k - 1; j++)
        {
            int nx = x + i, ny = y + j;

            if (oob(nx, ny))
                continue;
            if (abs(nx - x) + abs(ny - y) >= k)
                continue; // 영역이 아니면 패스
            if (brd[nx][ny])
            {
                hcnt++;
            }
        }
    }


    int cost = k * k + (k - 1) * (k - 1);
    return m * hcnt - cost;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test_case;
    int T;

    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case)
    {

        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
             이 부분에 여러분의 알고리즘 구현이 들어갑니다.

             입력이 작고 모든 경우를 탐색해야 됨 완전탐색

             보드 탐색
                각 위치별로 영역의 크기 1 ~ 30로 영역 체크
                얻은 수익과 비용으로 이익 구하기
                기존 이익과 비교 갱신

         */
        /////////////////////////////////////////////////////////////////////////////////////////////

        cin >> n >> m;
        brd.assign(n, vector<int>(n, 0));
        vis.assign(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> brd[i][j];
            }
        }
        calc(3, 3, 4);

        // 시뮬레이션 시작
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // 현재 위치 별로 마름모 호출
                for (int k = 1; k <= 30; k++)
                {
                    int profit = calc(i, j, k);
                    if (profit < 0)
                        continue;
                    ans = max(ans, hcnt);
                }
            }
        }

        cout << "#" << test_case << " " << ans << '\n';
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}
