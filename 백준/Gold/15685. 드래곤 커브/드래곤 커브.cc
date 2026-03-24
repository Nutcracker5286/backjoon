#include <bits/stdc++.h>
using namespace std;

/*

동 북 서 북
거꾸로
북 서 북 동
서 남 서 북
기존 방향을 반시계 한바퀴 돌고 기존세대값 더해주면 다음 세대의 선분이 됨

경계밖을 넘어가지 않음을 명시 따라서 경계 검사 x
세대가 주어지면 0세대가 될때까지 역순으로 진행

순방향 리스트 유지
다음 세대는 현재세대의 순방향 리스트를 거꾸로 읽고 해당 요소에 +3 더해서 반시계 방향

*/
int n, x, y, d, g, ans;
int brd[110][110];
// 동북서남
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--)
    {
        // 가로 세로 좌펴ㅛ
        cin >> x >> y >> d >> g;

        deque<int> dir;
        dir.push_back(d);

        // 주어진 세대 도달 까지
        for (int i = 0; i < g; i++)
        {
            deque<int> tmp;
            // 방향 리스트를 거꾸로 읽고 반시계 회전 시켜서 기존 요소에 추가하기
            for (int j = dir.size() - 1; j >= 0; j--)
            {
                tmp.push_back((dir[j] + 1) % 4);
            }

            // 다음세대의 방향을 리스트에 저장
            while (!tmp.empty())
            {
                dir.push_back(tmp.front());
                tmp.pop_front();
            }
        }

        while (!dir.empty())
        {
            brd[y][x] = 1;
            x += dx[dir.front()];
            y += dy[dir.front()];
            brd[y][x] = 1;
            dir.pop_front();
        }
    }

    // 정사각형 카운트
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (!brd[i][j])
                continue;
            // 좌상단 꼭짓점이라 가정
            if (brd[i][j + 1] && brd[i + 1][j] && brd[i + 1][j + 1])
                ans++;
        }
    }
    cout << ans;
}