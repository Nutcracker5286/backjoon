#include <bits/stdc++.h>
using namespace std;

int n, m; // 보드의 세로, 가로 크기
vector<vector<int>> board; // 보드의 상태를 저장하는 2차원 벡터
int ans; // 정답 저장
vector<pair<int, int>> cctv; // CCTV의 위치를 저장하는 벡터
vector<bool> isused; // CCTV 사용 여부를 저장하는 벡터

int dx[4] = {1, 0, -1, 0}; // 이동할 방향에 따른 세로 방향의 변화량
int dy[4] = {0, 1, 0, -1}; // 이동할 방향에 따른 가로 방향의 변화량

// CCTV가 보는 방향을 확인하여 해당 방향으로 직진하며 보이는 영역을 표시하는 함수
void check(int a, int b, int drt, vector<vector<int>>& temp) {
    // 보드의 범위를 벗어나거나 벽을 만날 때까지 반복
    while (1) {
        if (a < 0 || a >= n || b < 0 || b >= m || temp[a][b] == 6) return; // 범위를 벗어나거나 벽을 만나면 종료
        if (temp[a][b] == 0) temp[a][b] = 7; // 빈 공간이면 CCTV가 본 영역으로 표시
        a += dx[drt]; // 다음 위치로 이동
        b += dy[drt];
    }
}

// CCTV의 모든 경우를 탐색하는 재귀 함수
void recur(int cur, vector<vector<int>> t) {
    // 모든 CCTV에 대한 처리를 완료한 경우
    if (cur == cctv.size()) {
        int cnt = 0;
        // 남은 빈 공간의 수를 계산
        for (const auto& row : t) {
            cnt += count(row.begin(), row.end(), 0);
        }
        // 최솟값 업데이트
        ans = min(ans, cnt);
        return;
    }

    int x = cctv[cur].first; // 현재 CCTV의 세로 위치
    int y = cctv[cur].second; // 현재 CCTV의 가로 위치
    for (int i = 0; i < 4; i++) {
        vector<vector<int>> temp = t; // 보드의 상태를 복사하여 사용
        switch (board[x][y]) {
            // CCTV 종류에 따라 해당하는 방향을 표시
            case 1:
                check(x, y, i, temp);
                break;
            case 2:
                check(x, y, i, temp);
                check(x, y, (i + 2) % 4, temp);
                break;
            case 3:
                check(x, y, i, temp);
                check(x, y, (i + 1) % 4, temp);
                break;
            case 4:
                for (int j = 0; j < 2; j++) {
                    check(x, y, (i + j) % 4, temp);
                }
                check(x, y, (i + 2) % 4, temp);
                break;
            case 5:
                for (int j = 0; j < 4; j++) {
                    check(x, y, j, temp);
                }
                break;
        }
        // 다음 CCTV로 넘어감
        recur(cur + 1, temp);
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++ I/O 스트림과 C 표준 스트림 동기화 비활성화
    cin.tie(0); // cin과 cout의 묶음을 해제하여 실행 속도 향상

    cin >> n >> m; // 보드의 세로, 가로 크기 입력
    board.resize(n, vector<int>(m, 0)); // 보드 초기화

    // 보드의 상태 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            // CCTV 위치 저장
            if(board[i][j]==0) ans++;
            if (board[i][j] > 0 && board[i][j] < 6) {
                cctv.push_back({i, j});
            }
        }
    }

    recur(0, board); // 재귀 함수 호출하여 모든 경우 탐색
    cout<<ans;
}
