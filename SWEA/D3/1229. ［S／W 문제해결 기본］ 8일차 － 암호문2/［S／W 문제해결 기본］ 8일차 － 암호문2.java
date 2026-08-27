import java.io.*;
import java.util.*;

class Solution {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        // 테스트 케이스는 입력으로 주어지지 않고 항상 10개
        for (int tc = 1; tc <= 10; tc++) {

            // 원본 암호문의 길이
            int n = Integer.parseInt(br.readLine());

            LinkedList<Integer> list = new LinkedList<>();

            // 원본 암호문 입력
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int i = 0; i < n; i++) {
                list.add(Integer.parseInt(st.nextToken()));
            }

            // 명령어 개수
            int m = Integer.parseInt(br.readLine());

            // 모든 명령어
            st = new StringTokenizer(br.readLine());

            for (int cmd = 0; cmd < m; cmd++) {

                String command = st.nextToken();

                if (command.equals("I")) {

                    int x = Integer.parseInt(st.nextToken());
                    int y = Integer.parseInt(st.nextToken());

                    ListIterator<Integer> it = list.listIterator(x);

                    for (int i = 0; i < y; i++) {
                        int num = Integer.parseInt(st.nextToken());
                        it.add(num);
                    }

                } else if (command.equals("D")) {

                    int x = Integer.parseInt(st.nextToken());
                    int y = Integer.parseInt(st.nextToken());

                    ListIterator<Integer> it = list.listIterator(x);

                    for (int i = 0; i < y; i++) {
                        it.next();
                        it.remove();
                    }
                }
            }

            // 처음 10개 출력
            sb.append("#").append(tc);

            Iterator<Integer> it = list.iterator();

            for (int i = 0; i < 10; i++) {
                sb.append(" ").append(it.next());
            }

            sb.append("\n");
        }

        System.out.print(sb);
    }
}