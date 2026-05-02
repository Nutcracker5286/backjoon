#include <bits/stdc++.h>
using namespace std;
/*
바위를 n개 제거한 뒤, 인접한 지점 사이 거리의 최솟값을 최대화해야 한다.

바위 개수는 최대 50,000개이므로 제거할 바위를 조합으로 선택하는 방식은 불가능하다.
정답은 "최소 거리"이고, 이 값은 1부터 distance 사이에 있다.

어떤 거리 mid가 주어졌을 때,
남은 지점들 사이의 모든 간격을 mid 이상으로 만들 수 있는지 판정할 수 있다.

mid가 작으면 조건을 만족하기 쉽고,
mid가 커지면 조건을 만족하기 어려워진다.

즉 가능 여부는 다음과 같은 단조성을 가진다.

T T T T F F F

따라서 가능한 mid 중 최댓값, 즉 마지막 T를 이분 탐색으로 찾는다.

판정은 그리디로 한다.
출발점 0을 마지막으로 남긴 지점 prev로 두고,
바위를 왼쪽부터 확인한다.

현재 바위 rock과 prev 사이의 거리가 mid보다 작으면,
현재 바위를 남길 경우 최소 거리 조건을 위반하므로 현재 바위를 제거한다.

rock - prev < mid  => 현재 바위 제거

반대로 rock - prev >= mid이면,
현재 바위를 남길 수 있으므로 prev를 현재 바위로 갱신한다.

rock - prev >= mid => 현재 바위 유지, prev = rock

이 과정을 도착점 distance까지 포함해 수행했을 때,
제거한 바위 수가 n개 이하이면 mid는 가능한 최소 거리이다.

따라서 removed <= n 이면 가능,
removed > n 이면 불가능이다.
*/
bool solve(vector<int> &rocks, int mid,int n){
    int removed =0;
    int prev= 0;
    
    for(auto rock : rocks){
        if(rock - prev <mid){
            removed++;
        }
        else{
            prev = rock;
        }
    }
    return removed <= n;
}

int solution(int distance, vector<int> rocks, int n) {
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    int answer = 0;

    
    int st= 0, en=distance; //거리 최솟값
    
    while(st<=en){
        int mid = (st+en)/2;
        
        if(solve(rocks,mid,n)){
            answer =  mid;
            st=mid+1;
        }
        else{
            en=mid-1;
        }
    }
    
    
    return answer;
}