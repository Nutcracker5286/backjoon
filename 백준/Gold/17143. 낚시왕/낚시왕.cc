#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
/*
크기와 속도를 가진 상어를 잡고, 잡은 모든 상어 크기의 합 구하기

왼쪽에서 오른쪽으로 어부가 이동 , 단 오른쪽 바깥 이동시 종료

1 index임
1,2,3,4 = 북 남 동 서
를 북 동 남 서로 변경
시뮬레이션

1부터 열의 끝까지 시뮬레이션

현재열에서 가장가까운 상어 포획
    어부 열과 동일한지, 살아있는지, 가장가까운 행인지

잡힌 상어를  삭제 처리
    상어가 잡혔는지, 정답에 더했는지

상어 이동
    죽어 있으면 패스
    속력 바탕 최적화 처리
    충돌 판정용 보드에 충돌 확인, -1 초기화 상어 인덱스 담기
충돌 처리

복잡도 어부(열) * 상어 개수 * 상어 이동(속력)
100 * 100*100 * 1000 => 10억이라 최적화 필요
이동 부분에서 최적화 진행 주기 계산 처리
*/
struct shark
{
    int x, y, velo, dir, size;
    bool alive;
};
// a,f,h,d,g
// 0,5,7,3,6
int R, C, m, r, c, s, d, z, ans;
int brd[110][110];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<shark> sh;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> r >> c >> s >> d >> z;

        if (d == 2)
            d = 3;
        else if (d == 3)
            d = 2;
        d--;
        sh.push_back({r, c, s, d, z, 1});
    }

    // 어부 이동 및 시뮬레이션
    for (int fis = 1; fis <= C; fis++)
    {
        int tmp[110][110] = {};
        fill(&tmp[0][0], &tmp[0][0] + 110 * 110, -1);

        // 현재 열에서 가장 가까운 상어 포획
        int minRow = 1e9;
        int idx = -1;
        for (int i = 0; i < m; i++)
        {
            // 어부 열과 동일한지, 살아있는지, 가장가까운지
            if (sh[i].y != fis || !sh[i].alive || sh[i].x > minRow)
                continue;
            minRow = sh[i].x;
            idx = i;
        }

        // 상어가 잡힌 경우에 정답에 더하기, 삭제 처리
        if (idx != -1)
        {
            ans += sh[idx].size;
            sh[idx].alive = 0;
        }

        // cout << "\n 잡힌 상어 : " << idx << '\n';
        // 상어 이동
        for (int i = 0; i < m; i++)
        {
            // 죽어 있으면 패스
            if (!sh[i].alive)
                continue;

            // 주기 바탕 속력 최적화, 주기는 경계가 1인경우 예외 처리, 단 문제에서는 제한 해서 고려 x
            auto [x, y, velo, dir, size, alive] = sh[i];

            if (dir == 2 || dir == 0)
            { // 북,남
                velo %= (2 * (R - 1));
            }
            else
            {
                velo %= (2 * (C - 1));
            }

            // 남은 속도 만큼이동, 경계 반사 처리
            while (velo--)
            {
                x += dx[dir];
                y += dy[dir];
                if (x < 1 || y < 1 || x > R || y > C)
                {
                    dir = (dir + 2) % 4;
                    x += dx[dir] * 2;
                    y += dy[dir] * 2;
                }
            }

            // 충돌 판정용 보드 확인후에 충돌 처리
            if (tmp[x][y] != -1)
            { // 충돌 하는 경우
                if (sh[tmp[x][y]].size < size)
                { // 현재 이동하는 상어가 더 큰 경우
                    sh[tmp[x][y]].alive = 0;
                    tmp[x][y] = i;
                }
                else
                { // 있는게 더 큰경우
                    sh[i].alive = 0;
                }
            }

            // 충돌 하지 않는경우
            else
            {
                tmp[x][y] = i;
            }
            sh[i].x = x;
            sh[i].y = y;
            sh[i].dir = dir;
            // cout << (char)('A' + i)
            //      << "번 상어의 위치"
            //      << x << ", " << y
            //      << "의 방향 " << dir << '\n';
        }
    }
    cout << ans;
}
