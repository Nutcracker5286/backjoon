#include <string>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    vector<int> cnt(1000,0);
    for(auto c :array){
        cnt[c]++;
    }
    int maxCnt = *max_element(cnt.begin(),cnt.end());
    int maxIdx = max_element(cnt.begin(),cnt.end())-cnt.begin();
    int t=0;
    for(auto c:cnt){
        if(maxCnt == c) t++;
    }
    
    return t==1? maxIdx : -1;
}