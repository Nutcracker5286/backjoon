#include <string>
#include <vector>

// x가 큰 쪽
int gcd(int x, int y){
    if(y==0) return x;
    return gcd(y, x%y);
}

using namespace std;
/*
기약분수로 만듬, 분모가 2또는 5가 아닌수로 나눠지면 무한소수
*/
int solution(int a, int b) {
    int answer = 0, g;
    if(a>b)
        g = gcd(a,b);
    else
        g=gcd(b,a);

    a/=g; b/=g;
    
    while(b%2==0) b/=2;
    while(b%5==0) b/=5;
    //분모의 소인수 확인
    if(b==1) return 1;
    
    for(int i=2; i<=b; i++){
        if(b%i==0) return 2;
    }
    
}