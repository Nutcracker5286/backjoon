#include <string>
#include <bits/stdc++.h>

using namespace std;

void doSkill(vector<vector<int>> &diff, vector<int> &skill){
    int ty;
    ty= skill[0] == 1 ?-1:1;
    int cx = skill[1], cy=skill[2];
    int ex = skill[3], ey =skill[4];
    int deg = skill[5]*ty;
    diff[cx][cy]+=deg;
    diff[cx][ey+1]-=deg;
    diff[ex+1][cy]-=deg;
    diff[ex+1][ey+1]+=deg;

    
    
}






/*
스킬을 탐색하면서 요규하는 상태 적용 시키기
*/
int solution(vector<vector<int>> brd, vector<vector<int>> skill) {
    int answer = 0;
    vector<vector<int>> diff(brd.size()+1,vector<int>(brd[0].size()+1,0));
    for(auto a : skill){
        doSkill(diff,a);
    }
        

    // 가로 누적합
    for(int i = 0; i < brd.size(); i++){
        for(int j = 1; j < brd[0].size(); j++){
            diff[i][j] += diff[i][j-1];
        }
    }

    // 세로 누적합
    for(int j = 0; j < brd[0].size(); j++){
        for(int i = 1; i < brd.size(); i++){
            diff[i][j] += diff[i-1][j];
        }
    }

    // 최종 검사
    for(int i = 0; i < brd.size(); i++){
        for(int j = 0; j < brd[0].size(); j++){
            answer += (brd[i][j] + diff[i][j] > 0);
        }
    } 
    
    
    return answer;
}