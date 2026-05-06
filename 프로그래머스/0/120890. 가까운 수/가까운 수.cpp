#include <string>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array, int n) {
    int brt = INT_MAX;
    int answer=0;
    sort(array.begin(),array.end());
    for(auto c : array){
        if(abs(c-n)< brt){
          answer= c;
            brt=abs(c-n);
        } 
    }
    return answer;
}