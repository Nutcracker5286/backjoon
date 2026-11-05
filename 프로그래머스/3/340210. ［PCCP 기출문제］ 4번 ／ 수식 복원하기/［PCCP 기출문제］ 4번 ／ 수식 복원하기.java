
import java.util.*;

class Solution {
    public String[] solution(String[] expressions) {
        int n = expressions.length;
        boolean[] isCal = new boolean[n];
        boolean[] isBase = new boolean[10];

        ArrayList<String> answer = new ArrayList<>();

        // 가능한 진법은 우선 모두 true
        Arrays.fill(isBase, true);

        // 모든 수식에 등장하는 숫자로 최소 진법 결정
        int minBase = 2;

        for (String expression : expressions) {
            String[] tmp = expression.split(" ");

            for (int idx : new int[]{0, 2, 4}) {
                if (tmp[idx].equals("X")) continue;

                for (char c : tmp[idx].toCharArray()) {
                    minBase = Math.max(minBase, c - '0' + 1);
                }
            }
        }

        // 최소 진법보다 작은 진법 제거
        for (int base = 2; base < minBase; base++) {
            isBase[base] = false;
        }

        // 결과값이 알려진 수식으로 가능한 진법 찾기
        for (int i = 0; i < n; i++) {
            String[] tmp = expressions[i].split(" ");

            if (tmp[4].equals("X")) continue;

            isCal[i] = true;

            // 가능한 베이스 찾고 기록까지
            findBase(tmp, isBase);
        }

        // 수식 순회
        for (int i = 0; i < n; i++) {
            if (isCal[i]) continue;

            String[] tmp = expressions[i].split(" ");

            // 가능한 베이스 순회
            String bef = "";
            boolean first = true;
            boolean diff = false;

            for (int base = 2; base < 10; base++) {
                if (!isBase[base]) continue;

                int a = Integer.parseInt(tmp[0], base);
                int b = Integer.parseInt(tmp[2], base);
                String res = "";

                if (tmp[1].equals("+"))
                    res = Integer.toString(a + b, base);
                else
                    res = Integer.toString(a - b, base);

                // 이전 결과와 현재 결과가 다르면 ? 처리
                if (!first && !res.equals(bef)) {
                    diff = true;
                    break;
                }

                bef = res;
                first = false;
            }

            if (diff)
                tmp[4] = "?";
            else
                tmp[4] = bef;

            answer.add(String.join(" ", tmp));
        }

        return answer.toArray(new String[0]);
    }

    // 해당 수식이 가능한 진법을 찾고 불린에 기록하는 함수
    static void findBase(String[] tmp, boolean[] isBase) {
        // 가능한 베이스 순회
        for (int base = 2; base < 10; base++) {
            if (!isBase[base]) continue;

            int a = Integer.parseInt(tmp[0], base);
            int b = Integer.parseInt(tmp[2], base);
            String res = "";

            if (tmp[1].equals("+"))
                res = Integer.toString(a + b, base);
            else
                res = Integer.toString(a - b, base);

            // 다른 수식에서 성립 가능한 진법이 여기서 안 되면 제거
            if (!res.equals(tmp[4])) {
                isBase[base] = false;
            }
        }
    }
}
