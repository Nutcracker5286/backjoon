#include <bits/stdc++.h>
using namespace std;

/*
명함의 가로 세로 전환 가능
모든 명함을 수납 가능한 가장 작은 지각 만들기

따라서 명함 중 긴쪽을 한 방향 ex) 가로로 몰기
그러면 긴쪽에서 젤 긴 값, 짧은쪽에서 제일 긴 값만 추출


*/

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int maxW =0, maxH=0;
    for(auto c : sizes){
        int w = c[1], h =c[0];
        
        maxH = max(maxH, max(w,h));
        maxW = max(maxW, min(w,h));
    }
    
    return maxW*maxH;
}