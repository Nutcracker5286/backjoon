#include <bits/stdc++.h>
using namespace std;

/*
w길이의 다리를 n개의 트럭이 건너야 함
다리가 버티는 최대 하중은 L

대기 트럭을 큐로 관리
다리에 직접 트럭을 놓으면서 시간 카운트 진행

대기열이 비워지고, 다리 위에트럭이 없어야 종료

전진시킴
다리 무게와 대기열 트럭 무게 합이 하중 이하면
다리에 트럭 싣고 대기열에서 제거
*/

queue<int> q;
int n, w, L;
int bridge[105];

bool isEmpty()
{
    for (int i = 0; i < w; i++)
    {
        if (bridge[i] != 0)
            return false;
    }
    return true;
}

void fw()
{
    // 한칸씩 전진
    for (int i = w - 1; i >= 0; i--)
    {
        bridge[i + 1] = bridge[i];
    }
    bridge[0] = 0;
}

int total()
{
    int t = 0;
    for (int i = 0; i < w; i++)
    {
        t += bridge[i];
    }
    return t;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> L;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        q.push(t);
    }

    // 건너는 시뮬레이션 시작
    int ans = 0;
    // 대기열이 비워지고, 다리 위에트럭이 없어야 종료
    while (!q.empty() || !isEmpty())
    {
        fw();
        ans++;

        // 현재 다리위의 무게와 대기열 무게 합이 하중보다 작은지 체크
        if (!q.empty() && total() + q.front() <= L)
        {
            // 작으면 다리에 싣기
            bridge[0] = q.front();
            q.pop();
        }
    }
    cout << ans;
}