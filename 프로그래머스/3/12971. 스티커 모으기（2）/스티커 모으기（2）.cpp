#include <iostream>
#include <vector>
using namespace std;

/*
스티커를 뜯어서, 최대 점수를 얻기
입력이 커서  완탐 시2^10000 시간 복잡도

따라서 그리디, dp, 투포인터
단조성이 없으므로 투포인터,이분탐색은 불가
그리디는 모든 경우의 수를 보지 못함
dp 선택

테이블 정의
d[i] =  i번째 원소까지 고려시 스티커의 최대값

점화식
d[i] = max(d[i-1],d[i-2]+stic[i])

초기값
1번째를 택하면, n선택 불가
1번째 선택 x , n선택

두 경우로 나눠서 풀이

두개의 테이블 사용
*/
int solution(vector<int> st)
{
    int answer =0;
    int d1[100010]={};
    int d2[100010]={};
    int n = st.size();
    
    if(n==1) return st[0];
    
    
    
    // 0번 선택
    d1[0] = st[0];
    d1[1] = st[0];
    for(int i=2; i<n-1; i++){ //n-1번은 제외
        d1[i] = max(d1[i-1],d1[i-2]+st[i]);
    }
    d1[n-1]  = d1[n-2];
    
    
    //n-1번선택
    d2[1] = st[1];
    for(int i=2; i<n; i++){ 
        d2[i] = max(d2[i-1],d2[i-2]+st[i]);
    }
    
    
    
    return max(d1[n-1],d2[n-1]);
}