import java.util.*;
import java.io.*;

/*

상태 알고, 코딩

문제 풀기 = 알고 , 코딩이 문제 사항보다 커야함


알고, 코딩 올리기
    1.알고 공부
    2. 코딩 공부
    3. 문제 풀어 상승

모든 문제를 푸는 알고, 코딩력 얻는 최단 시간

문제 중복 풀이 가능

이전 경로 상관없이  현재 상태만 다음 문제 풀이에 고려

그리디 || dp || 다익스트라 (r,c를  노드로 생각)

그리디
    현재 풀수 있는 문제 선택해서 풀기
        시간 3 5 1
        시간 2 2 2
        모자른 2,2 이러면 손해 가능
dp
    테이블
        d[r][c] = 알고 r, 코딩 c일때 최소 공부 시간
    점화식
        d[r][c] =  [r-1][c], [r][c-1] , [r-문제획득][c-문제획득]
    
초기값 r,c = 0
*/
class Solution {
    
    // 필요 r, c, 얻는 r,c  푸는 시간 
    public int solution(int alp, int cop, int[][] problems) {
        int answer = 0;
        int mxA=0;
        int mxC =0;
        
        //이 이상 공부 필요 x
        for(int [] p : problems){
            mxA = Math.max(mxA,  p[0]);
            mxC= Math.max(mxC,  p[1]);

        }
        
        
        int inf = 0x7f7f7f7f;
        int [][] dp = new int[400][400];
        
        for(int [] d : dp)
        Arrays.fill(d, inf);
        alp  = Math.min(alp,mxA);
        cop  = Math.min(cop,mxC);

        
        
        //
        dp[alp][cop]=0;
        
        for(int r= alp; r<=mxA ; r++){
            for(int c= cop; c<=mxC ; c++){
                if(dp[r][c] == inf) continue;
                
                //알고 공부
                if( r< mxA)
                dp[r+1][c] =  Math.min(dp[r+1][c], dp[r][c] +1);
                
                
                //코딩 공부
                if( c< mxC)

                dp[r][c+1] =  Math.min(dp[r][c+1], dp[r][c] +1);
                
                //문제 풀이
                for(int [] p : problems){
                    // 필요 r, c, 얻는 r,c  푸는 시간 
                    
                    //못 풀면 패스
                    if(r < p[0]  || c <p[1]) continue;
                    int nr = Math.min(mxA,r+p[2]);
                    int nc = Math.min(mxC,c+p[3]);
                    dp[nr][nc] =  Math.min(dp[r][c]+p[4], dp[nr][nc]);
                    
                }
            }
        }
        
        
        
        return dp[mxA][mxC];
    }
}