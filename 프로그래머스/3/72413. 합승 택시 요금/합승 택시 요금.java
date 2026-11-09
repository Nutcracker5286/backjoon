
import java.util.*;

class Solution {

    static final int INF = 1_000_000_000;

    public int solution(int n, int s, int a, int b, int[][] fares) {

        int[][] dist = new int[n + 1][n + 1];

        // 1. 거리 초기화
        for (int i = 1; i <= n; i++) {
            Arrays.fill(dist[i], INF);
            dist[i][i] = 0;
        }

        // 2. 간선 등록 (무방향)
        for (int[] fare : fares) {
            int u = fare[0];
            int v = fare[1];
            int cost = fare[2];

            dist[u][v] = cost;
            dist[v][u] = cost;
        }

        // 3. 플로이드-워셜
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {

                    if (dist[i][k] == INF || dist[k][j] == INF)
                        continue;

                    dist[i][j] = Math.min(
                        dist[i][j],
                        dist[i][k] + dist[k][j]
                    );
                }
            }
        }

        // 4. 모든 합승 종료 지점 탐색
        int ans = INF;

        for (int k = 1; k <= n; k++) {
            if (dist[s][k] == INF ||
                dist[k][a] == INF ||
                dist[k][b] == INF)
                continue;

            int cost = dist[s][k] + dist[k][a] + dist[k][b];

            ans = Math.min(ans, cost);
        }

        return ans;
    }
}
