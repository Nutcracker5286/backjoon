#include <string>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers) {
    int answer = INT_MIN;
    vector<int> mask (numbers.size() , 0);
    fill(mask.end()-2,mask.end(),1);
    do{
        int id=0,idx=0;
        int t[2]={};
        for(auto c : mask){
            if(c){
                t[id++]=numbers[idx];
            }
            idx++;
        }
        answer = max(answer ,t[0]*t[1]);
    }while(next_permutation(mask.begin(),mask.end()));
    

    return answer;
}