

import java.io.*;
import java.util.*;

public class Solution {

    static int N, B, ans;
    static int[] h;

    static void dfs(int idx, int sum) {

        if (sum >= B) {
            ans = Math.min(ans, sum - B);
            return;
        }

        if (idx == N) return;

        dfs(idx + 1, sum + h[idx]); // 선택
        dfs(idx + 1, sum);          // 선택 X
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {

            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());

            h = new int[N];

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                h[i] = Integer.parseInt(st.nextToken());
            }

            ans = Integer.MAX_VALUE;

            dfs(0, 0);

            System.out.println("#" + tc + " " + ans);
        }
    }
}