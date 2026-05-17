#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    int d[2005]={}; // i칸에 도착하는 방법의 수
    d[1] = 1;d[2]=2;
    for(int i=3; i<=n; i++){
        d[i] = (d[i-1] + d[i-2])%1234567;
    }
    return d[n];
}