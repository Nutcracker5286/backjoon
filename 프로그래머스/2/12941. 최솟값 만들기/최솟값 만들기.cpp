#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/*
조합 , 조합 하면 복잡도 초과
dp 그리디 등으로 풀이
dp는 테이블 범위 초과 천의 3제곱  -> 그리고 이전에 뭘선택했는지도 안나옴
따라서 그리디 -> 작은것과 큰것곱
*/
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(), greater<int>{});
    for(int i=0; i<A.size(); i++)
        answer+=A[i]*B[i];
    int minV = INT_MAX;


    return answer;
}