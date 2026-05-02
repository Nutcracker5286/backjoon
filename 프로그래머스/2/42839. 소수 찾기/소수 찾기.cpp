#include <bits/stdc++.h>
using namespace std;

/*
문자열을 종이 조각으로 분리하고
모든 조합 생성
그다음 0~총개수만큼 분리하면서 set에 추가
*/

set<int> num;
vector<int> isUsed;
string arr;
bool isprime(int t){
    if( t< 2 ) return 0;
    for(int i=2; i*i <= t; i++){
        if(t%i==0) return 0;
    }
    return 1;
}

void solve(string cur){
    if(!cur.empty()){
        num.insert(stoi(cur));
    }
    
    for(int i=0; i<arr.size(); i++){
        if(isUsed[i]) continue;
        isUsed[i]=1;
        solve(cur+arr[i]);
        isUsed[i]=0;
    }
    
}

int solution(string numbers) {
    int answer = 0;
    arr = numbers;
    isUsed.assign(numbers.size(),0);
    sort(numbers.begin(),numbers.end());
    
    solve("");
    
    for(auto c: num){
        if(isprime(c)) answer++;
    }

    return answer;
}