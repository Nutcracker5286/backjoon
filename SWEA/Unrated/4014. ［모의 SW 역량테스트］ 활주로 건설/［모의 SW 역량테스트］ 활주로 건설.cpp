
#include <bits/stdc++.h>

using namespace std;
int n, l, ans;
vector<vector<int>> brd;

bool isRoad(vector<int> &line)
{
    vector<int> used(line.size(), 0);
    for (int i = 1; i < line.size(); i++)
    {
        int diff = line[i] - line[i - 1];
        if (diff == 0 || used[i]) // 같거나, 이미 설치되었으면 패스
            continue;
        if (abs(diff) > 1) // 설치 불가
            return false;
        if (diff < 0)
        { // 높 -> 낮
            for (int j = 0; j < l; j++)
            {
                if (i + j >= n || used[i + j]) // 정상 범위
                    return false;
                if (line[i + j] != line[i]) // 높이가 같아야 함
                    return false;
            }
            fill(used.begin() + i, used.begin() + i + l, 1);
        }
        else
        { // 낮 -> 높
            for (int j = 1; j <= l; j++)
            {
                if (i - j < 0 || used[i - j]) // 정상 범위
                    return false;
                if (line[i - j] != line[i - 1]) // 높이가 같아야 함
                    return false;
            }
            fill(used.begin() + i - l, used.begin() + i, 1);
        }
    }
    return true;
}

int main(int argc, char **argv)
{
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

             가로방향에 활주로가 생성될 수 있는지 체크
            90도 회전후
            다시 가로 방향 체크 == 원본의 세로 체크



            활주로 여부 탐색
                가로로 탐색 시행
                베이스를 0번째 지점으로
                    탐색 진행시 베이스와 같거나 이미 경사로면 컨티뉴
                    설치할수 있으면 설치
                    베이스를 현재 높이로 갱신,길을 만들 수 있음을 표시
         */

        cin >> n >> l;

        brd.assign(n, vector<int>(n, 0));
        ans = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> brd[i][j];

        // 가로 탐색
        for (int i = 0; i < n; i++)
        {
            vector<int> line;
            for (int j = 0; j < n; j++)
            {
                line.push_back(brd[i][j]);
            }
            ans += isRoad(line) == true;
        }

        // 세로 탐색
        for (int i = 0; i < n; i++)
        {
            vector<int> line;
            for (int j = 0; j < n; j++)
            {
                line.push_back(brd[j][i]);
            }
            ans += isRoad(line) == true;
        }

        /////////////////////////////////////////////////////////////////////////////////////////////
        cout << "#" << test_case << " " << ans << '\n';
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}