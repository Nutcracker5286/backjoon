import java.io.*;
import java.util.*;

public class Solution {

    static int n;
    static int[][] brd = new int[110][110];
    static int[][] dist = new int[110][110];

    static int[] dx = { 1, 0, -1, 0 };
    static int[] dy = { 0, 1, 0, -1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(
                new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            n = Integer.parseInt(br.readLine());

            // 거리 배열 초기화
            for (int i = 0; i < n; i++) {
                Arrays.fill(dist[i], Integer.MAX_VALUE);
            }

            // 지도 입력
            for (int i = 0; i < n; i++) {
                String line = br.readLine();
                for (int j = 0; j < n; j++) {
                    brd[i][j] = line.charAt(j) - '0';
                }
            }

            // {비용, x, y}, 비용 기준 최소 힙
            PriorityQueue<int[]> pq = new PriorityQueue<>(
                    (a, b) -> Integer.compare(a[0], b[0]));

            dist[0][0] = 0;
            pq.offer(new int[] { 0, 0, 0 });

            // 다익스트라
            while (!pq.isEmpty()) {
                int[] cur = pq.poll();

                int c = cur[0];
                int x = cur[1];
                int y = cur[2];

                // 오래된 거리 정보 무시
                if (c != dist[x][y])
                    continue;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;

                    int nc = c + brd[nx][ny];

                    if (nc >= dist[nx][ny])
                        continue;

                    dist[nx][ny] = nc;
                    pq.offer(new int[] { nc, nx, ny });
                }
            }

            System.out.println("#" + tc + " " + dist[n - 1][n - 1]);
        }
    }
}