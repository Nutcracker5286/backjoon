
#include <algorithm>
#include <iostream>

using namespace std;

// 시계방향
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, -1, 1};
int n;
int kind[110];
int brd[25][25];
int vis[25][25];

int cnt;
int ans;
int sx, sy;

bool oob(int x, int y)
{
    return x < 0 || y < 0 || x >= n || y >= n;
}

void make_rec(int x, int y, int dir, int cnt)
{
    for (int d = dir; d < 4; d++)
    {
        if (d > dir + 1)
            return;
        int nx = x + dx[d], ny = y + dy[d];

        // oob면 다른 후보
        if (oob(nx, ny))
            continue;
        // 한바퀴 돌았는지 체크
        if (d == 3 && nx == sx && ny == sy)
        {
            ans = max(ans, cnt);
            cout << "형성 성공, 영역 크기  : " << cnt << "\n";
            return;
        }
        if (kind[brd[nx][ny]])
            continue;
        kind[brd[nx][ny]] = 1;
        make_rec(nx, ny, d, cnt + 1);
        kind[brd[nx][ny]] = 0;
    }
}

int main(int argc, char **argv)
{
    int test_case;
    int T;
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case)
    {

        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
             이 부분에 여러분의 알고리즘 구현이 들어갑니다.
             가능한 대각사각형을 그리면서 겹치지 않는 종류만 선택

             백트래킹으로 풀이

             함수 정의
                현재 x,y 방문, cnt개수만큼 종류 체크, 방향은 dir
                현재 방향, 꺽은 방향 탐색
                    해당 방향 만큼 진행
                    oob면 컨티뉴 => 다른 방향도 후보이기 때문
                    dir==3 이고 시작점이랑 동일시
                        사각형 형성이기에  정답 갱신
                    먹은 종류면 컨티뉴
                    종류 먹음 처리
                    다음 호출
                    처리 해제
            베이스 조건
                탐색 가능 방향보다 더 가면, 더 이상 만들지 못함
                한바퀴 돌고 왔으면 종료


        */

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> brd[i][j];
            }
        }

        ans = 0;
        // 보드탐색
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // 현재 노드에서 사각형 그리기
                kind[brd[i][j]] = 1;
                sx = i;
                sy = j;
                make_rec(i, j, 0, 1);
                kind[brd[i][j]] = 0;
            }
        }
        ans == 0 ? ans = -1 : ans;
        cout << "#" << test_case << " " << ans << "\n";

        /////////////////////////////////////////////////////////////////////////////////////////////
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}