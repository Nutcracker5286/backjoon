#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int ans= 1;
    while(1){
        if((a+1)/2 == (b+1)/2){
            return ans;
        }
        a=(a+1)/2;
        b=(b+1)/2;
        ans++;
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return ans;
}