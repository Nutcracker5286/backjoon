#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*

초기 문제 실패 
현재 행에서 특정 열선택 시 바로 아래의 노드는 선택 못함
노드 방문시 최대갑승ㄹ 구하는 함수
완탐은 2의 10만 제곱이라 불가능
따라서 dp , 그리디, 투포인터 등의 알고리즘 생각
그리디는 가장 큰 값이 아래에 줄지어 있다면 반례가 됨
투포인터 정렬된다고 해결하기 어려움
파라메틱 서치 정렬하고 판단하기 어려움
따라서 dp 
이전 선택 열의 열값을 고를 수 없다 => 이전 선택이 미래에 영향을 미침
이전에 무슨 번호를 선택했는지로 정보 압축 가능
n-1행의 값들로 n행의 값들을 구할 수 있음
따라서 현재 최적값으로 미래 최적값을 구할 수 있음 => 작은 최적해로 큰 최적해 생성 가능

dp [i,j] i행 j열 밞았을때 최적값
*/


int solution(vector<vector<int> > land)
{
    int answer = 0;
    int dp[100005][5]={};
    int n = land.size();
    for(int i=0; i<land.size(); i++){
        for(int j=0; j<4; j++){
            if(i==0){ //초기화
                dp[i][j]=land[i][j];
                continue;
            }
            //이전행에 따라서 선택 고려
            dp[i][0] =land[i][0] +max({dp[i-1][1],dp[i-1][2],dp[i-1][3]});
            dp[i][1] =land[i][1] +max({dp[i-1][0],dp[i-1][2],dp[i-1][3]});
            dp[i][2] =land[i][2] +max({dp[i-1][1],dp[i-1][0],dp[i-1][3]});
            dp[i][3] =land[i][3] +max({dp[i-1][1],dp[i-1][2],dp[i-1][0]});
            
            
        }
    }
    
    answer = *max_element(dp[n-1],dp[n-1]+land[0].size());

    return answer;
}