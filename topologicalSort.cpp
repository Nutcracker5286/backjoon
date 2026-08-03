#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200];
int deg[200];
int n;

bool tSort()
{
    vector<int> res;
    queue<int> q;

    // 들어오는 간선 0인 노드 추가
    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        // 큐에서 꺼낸 것이 현재 정렬 순서
        res.push_back(cur);

        for (int nxt : adj[cur])
        {
            deg[nxt]--;
            if (deg[nxt] == 0)
                q.push(cur);
        }
    }

    if (res.size() != n)
    { // 사이클이 형성되어 정렬이 실패한 경우
        cout << "cycle exists";
        return false;
    }
    return true; // 정렬 성공
}