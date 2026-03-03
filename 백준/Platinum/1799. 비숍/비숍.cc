/*
초기풀이는 부분집합의 개수 뽑는것으로 진행
tle 발생 => 시간 복잡도가 2^(체스판의 최대 크기=100) 실패

풀이 실패

체크판의 특성상 흑백 분리를 진행
2^50 + 2^50으로 줄어듬
비솝은 흑색에 있는거는 흑색만 공격 가능
백색에 있는거는 백색만 공격 가능


*/

// 오스만 후기 안봐도 됨
#include <bits/stdc++.h>
using namespace std;

int brd[110][110];
int up[300];   // 우상대 , x+y
int down[300]; // 우하대 , x+n-1-y
int n;
int ans[2];
vector<pair<int, int>> gr[2]; // e동일

void solve(int k, int color, int cnt)
{
    if (k == gr[color].size())
    { // 해당 색깔의 제공된 비숍 개수만큼의 깊이를 가지면
        ans[color] = max(ans[color], cnt);
        return;
    }
    // 이번 깊이에서 선택을 안 하는 경우
    solve(k + 1, color, cnt);
    // 선택하는 경우
    auto [x, y] = gr[color][k];
    if (!up[x + y] && !down[x - y + n - 1])
    {
        up[x + y] = down[x - y + n - 1] = 1;
        solve(k + 1, color, cnt + 1);
        up[x + y] = down[x - y + n - 1] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> brd[i][j];
            if ((i + j) % 2 == 0 && brd[i][j] == 1)
            { // 백
                gr[0].push_back({i, j});
            }
            else if ((i + j) % 2 == 1 && brd[i][j] == 1)
            { // 흑
                gr[1].push_back({i, j});
            }
        }
    }

    solve(0, 0, 0);
    solve(0, 1, 0);
    cout << ans[0] + ans[1];
}