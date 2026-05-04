#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int ans = 0;
    string tmp = to_string(num);
    string tr = to_string(k);
    ans= tmp.find(tr);
    return ans!=-1 ? ans+1 : -1;
}