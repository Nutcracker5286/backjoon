#include <string>
#include <vector>

using namespace std;

bool isp(int c){
    for(int i=2; i*i<=c; i++){
        if(c%i==0) return 0;
    }
    return 1;
}


int solution(int n) {
    int answer = 0;
    int pcnt = 0;
    
    if(n<=2) return 0;
    for(int i=2; i<=n; i++){
        if(isp(i)) pcnt++;
    }
    return n-pcnt-1;
}