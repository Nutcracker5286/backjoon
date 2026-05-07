#include <string>
#include <vector>

using namespace std;

bool isth(int t){
    string tmp = to_string(t);
    return tmp.find('3')+1;
}

int solution(int n) {
    int answer = 1;
    
    //3의 배수이거나 3이 들어가면 다음 숫자로
    for(int i=1; i<=n; i++,answer++){
        while(isth(answer) || answer%3==0){
            answer++;
        }

    }
    return answer-1;
}