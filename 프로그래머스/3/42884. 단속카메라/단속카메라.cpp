#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
백준의 회의실 배정과 동일한 문제
현재시점이후 기준, 진입시점이 현재 이후이고, 가장 빨리 끝나는 카메라를 선택
*/
int solution(vector<vector<int>> routes) {
    int answer = 0;
    int cam  = -0x7f7f7f7f;
    
    sort(routes.begin(),routes.end(),[](auto a, auto b){
        if(a[1] == b[1])
            return a[0]<b[0];
        return a[1] < b[1];
    });
    
    
    for(auto r : routes){
        if(r[0] <= cam) continue;
        
        answer++;
        cam = r[1];
    }
        
        
    
    
    return answer;
}