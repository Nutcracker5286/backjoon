
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

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
             플로이드는 보드 배열 하나를 정점으로 보면  v =10000이라 불가능
             따라서 다익스트라로 풀이
             보드는 간선 비용이라고  생각
             간선은 사방 탐색
         */
        /////////////////////////////////////////////////////////////////////////////////////////////
        int n;
        cin >> n;
        const int INF = 0x7f7f7f7f;
        vector<vector<int>> brd(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++)
        {
            string row;
            cin >> row;
            for (int j = 0; j < n; j++)
            {
                brd[i][j] = row[j] - '0';
            }
        }

        vector<vector<int>> dist(n, vector<int>(n, INF));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        dist[0][0] = 0;
        pq.push({dist[0][0], 0, 0});

        while (!pq.empty())
        {
            auto [curCost, curX, curY] = pq.top();
            pq.pop();

            if (curCost != dist[curX][curY])
                continue;

            for (int d = 0; d < 4; d++)
            {
                int nx = curX + dx[d], ny = curY + dy[d];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;
                if (dist[nx][ny] <= curCost + brd[nx][ny])
                    continue;
                dist[nx][ny] = curCost + brd[nx][ny];
                pq.push({dist[nx][ny], nx, ny});
            }
        }
        cout << "#" << test_case << " " << dist[n - 1][n - 1] << '\n';
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}