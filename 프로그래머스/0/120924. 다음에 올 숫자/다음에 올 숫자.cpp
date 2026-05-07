#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    int a = common[0], b=common[1], c= common[2];
    if(b-a == c-b) return common[common.size()-1]+ c-b;
    
    return common[common.size()-1]*(b/a);
}