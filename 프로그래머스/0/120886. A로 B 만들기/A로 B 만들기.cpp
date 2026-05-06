#include <string>
#include <bits/stdc++.h>

using namespace std;

int solution(string before, string after) {
    int answer = 0;
    map<char,int> m ;
    
    for(auto c: before)
        m[c]++;
    
    for(auto c: after){
        if(m[c]==0)
            return 0;
        if(m[c]!= count(after.begin(),after.end(),c)) return 0;
    }
    return 1;
}