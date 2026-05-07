#include <string>
#include <bits/stdc++.h>

using namespace std;

int solution(int balls, int share) {
    int answer = 0;
    vector<int> mask(balls,0);
    fill(mask.end()-share, mask.end(),1);
    do{
        answer++;
    }while(next_permutation(mask.begin(),mask.end()));
    return answer;
}