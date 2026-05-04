#include <string>
#include <vector>

using namespace std;


int ispow(int n){
    for(int i=1; i*i<=n; i++)
        if(i*i==n)  return 1;
    return 2;
}
int solution(int n) {
    int answer = 0;
    return ispow(n);
}