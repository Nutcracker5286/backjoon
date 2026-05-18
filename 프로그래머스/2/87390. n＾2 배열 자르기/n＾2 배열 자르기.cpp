#include <string>
#include <vector>

using namespace std;
// 가로 세로 중 큰 좌표값의 값이 곧 값
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    long long cnt = right-left +1;
    
    for(long long i=0; i<cnt; i++){
        int x =  (left+i)/n , y =(left+i)%n;
        answer.push_back(max(x,y)+1);
    }
    return answer;
}