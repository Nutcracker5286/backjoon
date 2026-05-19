#include <string>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_set<int> left;
    unordered_map<int, int> right;
    
    //처음에는 오른쪽에 몰빵 가정
    for(auto c : topping){
        right[c]++;
    }
    
    
    //천천히 왼쪽에 추가하면서 탐색
    for(int i=0; i<topping.size()-1; i++){
        left.insert(topping[i]);
        
        right[topping[i]]--;
        
        if(right[topping[i]] == 0){
            right.erase(topping[i]);
        }
        
        if(left.size() ==right.size()) answer++;
    }
    
    return answer;
}