#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    for(int i=-50; i<=1000; i++){
        int tmp =0;
        vector<int> can;
        for(int j=i; j<i+num; j++){
            tmp+=j;
            can.push_back(j);
        }
        if(tmp ==total)
            return can;
    }
    return answer;
}