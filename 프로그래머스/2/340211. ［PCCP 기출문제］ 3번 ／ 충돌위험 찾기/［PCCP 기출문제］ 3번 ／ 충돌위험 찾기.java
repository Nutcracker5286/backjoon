import java.util.*;


class Solution {
    static int[][]points;
    static int[][]routes;
    static int n,m,x;
    static Robot[] bot;
    
    /*
    포인트 N개
    운송 경로 M개
        첫 포인트 부터, 끝까지 순서대로 방문
    로봇 X대
        0초에 동시 출발
        상하좌우 1칸 이동가능
        항상 최단거리 이동
        행 단위 우선
            장애물이 존재X
            맨해튼 거리가 최단거리임을 보장
    마지막 포인트에 도착했으면
    운송 마치고 종료 처리
    
    이동 중 같은 좌표 로봇 2대이상 == 충돌업
    
    모든 로봇이 운행이 종로될때  누적된 충돌업 카운트
    
    
    시간별로 시뮬레이션
        종료 조건 = 모든 로봇 종료
        
        종료된 로붓을 제외하고 다음 경로로 한칸씩 이동
            이동전 좌표 기준 카운트 배열 감소
            이동 후 카우트 배열 증가
            동일좌표 2이면 위험 up
            현재 경로== 목표 점
                넥스트 점을 다음 점으로
                다음 점 == 끝점
                    종료시키고 breakl

    */
    public int solution(int[][] points, int[][] routes) {
        int answer = 0;
        this.points = points;
        this.routes = routes;
        n = points.length;
        m = routes[0].length;
        x =routes.length;
        bot = new Robot[x+1];
        int cnt[][] = new int[110][110];
        
        //로봇 초기화
        for(int i=0; i<x; i++){
            int idx = routes[i][0]-1;
            int x =  points[idx][0]-1;
            int y = points[idx][1]-1;
            int nxt=1;
            bot[i] =  new Robot(x,y,nxt, true);
            cnt[x][y]++;
            //초기화시 중복 여부 체크
            if(cnt[x][y] ==2) answer++;
        }
        
        
            
//            시간별로 시뮬레이션
//         종료 조건 = 모든 로봇 종료
        while(!isAllDone()){
//         종료된 로붓을 제외하고 다음 경로로 한칸씩 이동
            for(int i=0; i<x; i++){
                if(!bot[i].alive) continue;
                int cx = bot[i].x;
                int cy = bot[i].y;
//             이동전 좌표 기준 카운트 배열 감소
                cnt[cx][cy]--;
                
                //현재 목적지 좌표
                int idx =routes[i][bot[i].nxt]-1;
                int  curX = points[idx][0]-1;
                int  curY = points[idx][1]-1;
                
                int nx =cx, ny =cy;
                if(curX != cx)
                    nx = cx > curX ? cx-1:cx+1;
                else if(curY != cy)
                    ny = cy > curY ? cy-1:cy+1;

                bot[i].x = nx;
                bot[i].y = ny;
//             이동 후 카우트 배열 증가
                cnt[nx][ny] ++;

                // 현재 목적지 도달시 
                if(nx == curX && ny == curY){
                    if(bot[i].nxt== m-1){
                    bot[i].alive = false;
                    continue;
                }
                    bot[i].nxt++;
                }

            }
            
            for(int i=0; i<=100; i++){
                for(int j=0; j<=100; j++){
                    if(cnt[i][j]>=2) answer++;
                }
            }
            
            
            for(int i=0; i<x; i++){
        //마지막 목적지라면
                if(bot[i].nxt== m-1 && !bot[i].alive){
                    bot[i].nxt +=10;
                    cnt[bot[i].x][bot[i].y]--;
                    continue;
                }
            }
        }
        
        return answer;
    }
    
    static boolean isAllDone(){
        for(int i=0; i<x; i++){
            if(bot[i].alive) return false;
        }
        return true;
    }
    
    static class Robot{
        int x,y, nxt;
        boolean alive;
        
        Robot(int x, int y, int nxt,boolean alive){
            this.x = x;
            this.y = y;
            this.nxt =nxt;
            this.alive =alive;
        }
    }
    
    
    
}