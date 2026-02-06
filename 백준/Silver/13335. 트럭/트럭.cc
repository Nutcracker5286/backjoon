/*
큐로 대기 하는 트럭 관리

다리 배열에서 한칸씩 이동하면서 시간 카운트

현재 다리 무게를 계산하고 최대 하중
보다 낮으면 한칸 이동
무게와 대기열의 트럭 무게 합이 하중보다 작으면 다리에 싣기
*/
#include <bits/stdc++.h>
using namespace std;

int road[105];
queue<int> tr;
int n, w, L, ans;

bool isEmpty()
{
    for (int i = 0; i < w; i++)
        if (road[i] != 0)
            return 0;
    return 1;
}

int calc()
{
    int sum = 0;
    for (int i = 0; i < w; i++)
        sum += road[i];
    return sum;
}

void go()
{
    for (int i = w - 1; i > 0; i--)
    {
        road[i] = road[i - 1];
    }
    road[0] = 0;
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
        tr.push(t);
    }

    while (!tr.empty() || !isEmpty())
    {
        go(); // 한칸 전진
        ans++;
        // 다리 무게 계산
        int cur = calc();

        // 최대 하중이하면
        if (cur <= L)
        {
            if (!tr.empty() && cur + tr.front() <= L)
            {
                road[0] = tr.front();
                tr.pop();
            }
        }
    }
    cout << ans;
}