class Solution {

    /*
    이분탐색
    불가 불가 가능 가능
    */
    public int solution(int[] diffs, int[] times, long limit) {
        int answer = 0;

        long st = 1;
        long en = 100000;

        while (st < en) {
            long mid = (st + en) / 2;

            if (solve(diffs, times, limit, mid)) {
                en = mid;
            }
            else {
                st = mid + 1;
            }
        }

        return (int) st;
    }

    /*
    숙련도 >= 난도  현재시간 추가
    else
        실패횟수 * (현재 시간 + 이전 시간) + 현재 시간
    */
    public boolean solve(int[] diffs, int[] times, long limit, long mid) {
        long tot = 0;
        int len = diffs.length;

        for (int i = 0; i < len; i++) {
            int diff = diffs[i];
            int time = times[i];

            if (mid >= diff) {
                tot += time;
            }
            else {
                long prev = 0;
                if (i - 1 >= 0) {
                    prev = times[i - 1];
                }

                tot += (diff - mid) * (time + prev) + time;
            }

            // 제한 시간 초과 시 즉시 불가능 반환
            if (tot > limit) return false;
        }

        return true;
    }
}