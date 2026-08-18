#include <string>
#include <bits/stdc++.h>

using namespace std;

// 타입 시작x,y 끝 x,y 배수
void makeDiff(vector<int> &v, vector<vector<int>> &diff){
    int deg = (v[0] ==1?  -v[5] : v[5]);
    int sx = v[1], sy= v[2];
    int ex = v[3], ey= v[4];
    
    diff[sx][sy] += deg;
    diff[sx][ey+1]  -=deg;
    diff[ex+1][sy] -=deg;
    diff[ex+1][ey+1]+=deg;
}


int solution(vector<vector<int>> brd, vector<vector<int>> skill) {
    int answer = 0;
    
    int n =brd.size(), m = brd[0].size();
    
    
    //차분 배열 설정
    vector<vector<int>> diff(n+1, vector<int>(m+1,0));
    
    for(auto v : skill){
        makeDiff(v, diff);
    }
    
    //가로 누적합
    for(int i=0; i<n; i++){
        for(int j=1; j<m; j++){
            diff[i][j]+=diff[i][j-1];
        }
    }
    
    
    //세로 누적합
    for(int i=0; i<m; i++){
        for(int j=1; j<n; j++){
            diff[j][i]+=diff[j-1][i];
        }
    }
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            answer+=(diff[i][j]+brd[i][j]>0);
        }
    }
    
    
    return answer;
}