#include <string>
#include <bits/stdc++.h>

using namespace std;
// 집합으로 요소 추가, 원형 큐 탐색,길이를 증가시키면서 집합에 요소 추가 
int solution(vector<int> els) {
    int ans = 0;
    set<int> s;
    for(auto c: els){
        s.insert(c);
    }
    
    for(int i=0; i<els.size(); i++){
        int tmp = els[i];
        int cnt=1;
        for(int j=(i+1)%els.size(); cnt<=els.size(); j=(j+1)%els.size()){
            cnt++;
            tmp+=els[j];
            if(cnt<=els.size())
            s.insert(tmp);
        }
    }
    
    return s.size();
}