import java.util.*;
import java.io.*;

/*

디딤돌은 밟으면 -1
0이되면 밟을 수 없으,  그 다음 디딤돌로 도약
밟을 수 있는 디딤돌 여러개면 가장 가까운걸로


단순시뮬
-> 무한대 * 10만

n = 10만
n, nlogn

dp, 그리디, 이탐, 투포

징검다리를 밟다보면 연속 0 구간이 k이상이면 불가능

1명 가능 ... x명 가능  x+1명 불가능 ..
단조성
이탐 진행
*/



class Solution {
    public int solution(int[] stones, int k) {
        int answer = 0;
        int en =0;
        int st=0;
        
        for(int i=0; i< stones.length; i++){
            en = Math.max(en,stones[i]);
        }
        
        
        while(st <en){
            int mid =  (st + en+1)/2;
            if(solve(mid,stones,k)){
                st = mid;
            }
            else {
                en = mid-1;
            }
        }
        
        
        
        
        return st;
    }
    
    
    static boolean solve(int mid, int[] stones, int k){
        int cnt=0;
        for(int i=0; i<stones.length; i++){
            if(mid > stones[i]) {
                cnt++;
                if(cnt>= k) 
                    return false;
            }
            else
                cnt=0;
        }
        return true;
    }
    
}