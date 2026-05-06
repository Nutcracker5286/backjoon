#include <string>
#include <vector>

using namespace std;
/*
숫자면 추출
다음이 문자거나 끝이면 정답에 더하기 아니면 임시수를 10씩 곱해가며 진행 
*/

int solution(string my_string) {
    int answer = 0;
    

        int tmp =0;
    for(int i=0; i<my_string.size(); i++){
        if(isdigit(my_string[i])){
            tmp*=10;
            tmp+=my_string[i]-'0';
        }
        else{
            answer+=tmp;
            tmp=0;
        }
    }
    
    return answer+tmp;
}