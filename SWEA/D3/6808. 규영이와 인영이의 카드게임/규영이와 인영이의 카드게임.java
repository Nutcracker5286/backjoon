

import java.io.*;
import java.util.*;

class Solution {

    static int[] gyu = new int[9];
    static boolean[] used = new boolean[19];
    static int win;

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {

            Arrays.fill(used, false);

            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int i = 0; i < 9; i++) {
                gyu[i] = Integer.parseInt(st.nextToken());
                used[gyu[i]] = true;
            }

            win = 0;

            solve(0, 0, 0);

            int total = 1;
            for (int i = 1; i <= 9; i++) {
                total *= i;
            }

            sb.append("#")
              .append(tc)
              .append(" ")
              .append(win)
              .append(" ")
              .append(total - win)
              .append("\n");
        }

        System.out.print(sb);
    }

    static void solve(int cur, int gyuScore, int inScore) {

        if (cur == 9) {
            if (gyuScore > inScore) {
                win++;
            }
            return;
        }

        for (int card = 1; card <= 18; card++) {

            if (used[card])
                continue;

            used[card] = true;

            if (gyu[cur] > card) {
                solve(
                    cur + 1,
                    gyuScore + gyu[cur] + card,
                    inScore
                );
            } else {
                solve(
                    cur + 1,
                    gyuScore,
                    inScore + gyu[cur] + card
                );
            }

            used[card] = false;
        }
    }
}