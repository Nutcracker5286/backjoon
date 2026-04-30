#include <bits/stdc++.h>
using namespace std;
/*
정답 = (종류별 의상 개수 + 1)을 전부 곱한 뒤 - 1
따라서 map에서 ++해서 개수 체크하고 곱하면 됨
*/
int solution(vector<vector<string>> clothes) {
    int ans = 1;
    
    map<string, int> hm ;
    for(auto c :clothes){
        hm[c[1]]++;
    }
    
    for(auto c : hm){
        ans*=(c.second+1);
    }
    return ans-1;
}