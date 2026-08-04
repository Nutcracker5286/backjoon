#include <string>
#include <vector>

using namespace std;
const int  BASE=1000000007;
int d[60010];

int solution(int n) {
    int answer = 0;
    d[1]=1;
    d[2]=2;
    
    for(int i=3; i<60005; i++)
        d[i]=  (d[i-1] + d[i-2])%BASE;
    
    
    
    return d[n];
}