import java.io.*;
import java.util.*;

public class Solution {

    static int N;
    static long[] x, y;
    static boolean[] vis;

    static class Edge implements Comparable<Edge> {
        int v;
        long cost;

        Edge(int v, long cost) {
            this.v = v;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge o) {
            return Long.compare(this.cost, o.cost);
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {

            N = Integer.parseInt(br.readLine());

            x = new long[N];
            y = new long[N];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                x[i] = Long.parseLong(st.nextToken());
            }

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                y[i] = Long.parseLong(st.nextToken());
            }

            double E = Double.parseDouble(br.readLine());

            vis = new boolean[N];

            PriorityQueue<Edge> pq = new PriorityQueue<>();

            // 시작 정점
            pq.offer(new Edge(0, 0));

            long total = 0;
            int cnt = 0;

            while (!pq.isEmpty()) {

                Edge cur = pq.poll();

                // 이미 MST에 들어간 정점
                if (vis[cur.v])
                    continue;

                // MST에 포함
                vis[cur.v] = true;
                total += cur.cost;
                cnt++;

                // 모든 정점 포함 완료
                if (cnt == N)
                    break;

                // 현재 정점에서 아직 방문하지 않은 모든 정점으로 간선 생성
                for (int nxt = 0; nxt < N; nxt++) {

                    if (vis[nxt])
                        continue;

                    long dx = x[cur.v] - x[nxt];
                    long dy = y[cur.v] - y[nxt];

                    long cost = dx * dx + dy * dy;

                    pq.offer(new Edge(nxt, cost));
                }
            }

            sb.append("#")
              .append(tc)
              .append(" ")
              .append(Math.round(total * E))
              .append('\n');
        }

        System.out.print(sb);
    }
}