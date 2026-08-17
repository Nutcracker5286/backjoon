#include <string>
#include <bits/stdc++.h>

using namespace std;
/*
총 차량 개수에서 범위 겹치는 차량 찾기
- 겹치는 횟수+1을 정답에
*/
int solution(vector<vector<int>> routes) {
     // 진출 지점 기준 오름차순
    sort(routes.begin(), routes.end(),
         [](const vector<int>& a, const vector<int>& b) {
             return a[1] < b[1];
         });

    int answer = 0;

    // 아직 카메라 없음
    int camera = -30001;

    for (auto& route : routes) {
        int start = route[0];
        int end = route[1];

        // 현재 카메라가 이 차량의 진입 지점보다 앞에 있으면
        // 이 차량은 기존 카메라를 만나지 못함
        if (camera < start) {
            camera = end;
            answer++;
        }
    }
    
    return answer;
}