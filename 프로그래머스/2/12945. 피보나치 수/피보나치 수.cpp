#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int d[1000000]={};
    int answer = 0;
    d[2]=d[1]=1;
    for(int i=3; i<=n; i++){
        d[i]=(d[i-1]+d[i-2])%1234567;
    }
    return d[n];
}