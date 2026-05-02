#include <bits/stdc++.h>
using namespace std;

/*
명함의 가로 세로 전환 가능
모든 명함을 수납 가능한 가장 작은 지각 만들기

가능한 길이 중 최대 길이 찾기
그걸 가로로 설정
나머지 좌표들을 가로 세로 중 짧은 쪽을 새 벡터에 담기
새 백터 내림차 정렬, 제일 앞에 것 제출


*/
int w,h;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int ix =0, idx;
    int mn = 0;
    for(auto c: sizes){
        int tmp = max(c[0],c[1]);
        if(tmp > mn){
            mn =tmp;
            idx= ix;
        }
        ix++;
    }
    
    
    int x = sizes[idx][0] , y =sizes[idx][1];
    int mx = max(x,y);
    int my = min(x,y);
    
    // 해당 idx 제외하고 작은쪽 길이 삽입
    vector<int> res;
    res.push_back(my);
    for(int i=0; i<sizes.size(); i++){
        if(i==idx) continue;
        res.push_back(min(sizes[i][0],sizes[i][1]));
    }
    sort(res.begin(),res.end(), greater<int>{});
    answer = mx *res[0]; 
    
    
    
    
    return answer;
}