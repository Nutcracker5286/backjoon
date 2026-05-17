#include <string>
#include <bits/stdc++.h>

using namespace std;

bool issame(    map<string, int> &a,     map<string, int> &b){
    for(auto [k,v] : a){
        if(b[k] != v) return false;
    }
    return true;
}

/*
원하는 상품, 개수가 모두 포함되는 날짜의 경우의 슈를 반납
단 10일간의 제품이 일치 해야 함
따라서 슬라이딩 윈도우
*/
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;
    map<string, int> brt;
    
    //물품당 개수 기록
    for(int i=0; i<want.size(); i++){
        m[want[i]]=number[i];
    }
    
    //처음 윈도우 초기화
    for(int i=0; i<10; i++){
        brt[discount[i]]++;
    }
    if(issame(m,brt)) answer++;
    for(int i =1; i+10 <=discount.size(); i++ ){
        brt[discount[i-1]]--;
        brt[discount[i+9]]++;
        if(issame(m,brt)) answer++;
    }

    return answer;
}