#include <string>
#include <bits/stdc++.h>

using namespace std;
/*
개수가 많은 귤부터 채워나가서 k보다 커지면, 사러 다른 종류의 수가 나옴
*/
int solution(int k, vector<int> ta) {
    int answer = 0;
    int w[10000005]={};
    vector<pair<int,int>> brt ; // 귤 개수, 귤 크기
    int n = *max_element(ta.begin(),ta.end());
    for(int i=0; i<ta.size(); i++){
        w[ta[i]]++;
    }
    for(int i=0; i<=n; i++){
        if(w[i]!=0) brt.push_back({w[i],i});
    }
    
    sort(brt.begin(),brt.end(), greater<pair<int,int>>{});
    
    int tmp =0;
    for(int i=0; i<brt.size(); i++){
        tmp+=brt[i].first;
        if(tmp>=k){
            return i+1;
        }
    }
    
    return answer;
}