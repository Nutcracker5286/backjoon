import java.util.*;


class Solution {
    public int solution(int[] a) {
        int answer = 0;
        int n =a.length;
        int left[] = new int [n];
        int right[] = new int [n];
        
        Arrays.fill(left, 1000000010);
        Arrays.fill(right, 1000000010);

        left[0] = a[0];
        for(int i=1; i< left.length; i++){
            left[i] = Math.min(left[i-1], a[i]);
        }
        
        right[n-1] =  a[n-1];
        for(int i= n-2; i>=0 ; i--){
            right[i] = Math.min(right[i+1],a[i]);
        }

        
        // 왼쪽 가장 작은 < 현재탐색수
        // 오른쪽 가장 작은 < 현재 탐색 수 => 이면 최후 후보 풍선 불가
        answer+=2;
        for(int i=1; i<n-1; i++){
            if(left[i-1] <a[i] && right[i+1] <a[i] ) continue;
            answer++;
        }
        
        
        return answer;
    }
}