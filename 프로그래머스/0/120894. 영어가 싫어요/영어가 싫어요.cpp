#include <string>
#include <vector>

using namespace std;



long long solution(string numbers) {
    long long answer = 0;
    string bef ="";
    for(int i=0; i<numbers.size();){
        if(numbers[i]=='z'){
            bef+='0';
            i+=4;
        }
        else if(numbers[i]=='o'){
            bef+='1';
            i+=3;
        }
        else if(numbers[i]=='t' && numbers[i+1]=='w'){
            bef+='2';
            i+=3;
        }else if(numbers[i]=='t' && numbers[i+1]=='h'){
            bef+='3';
            i+=5;
        }else if(numbers[i]=='f' && numbers[i+1]=='o'){
            bef+='4';
            i+=4;
        }else if(numbers[i]=='f' && numbers[i+1]=='i'){
            bef+='5';
            i+=4;
        }else if(numbers[i]=='s' && numbers[i+1]=='i'){
            bef+='6';
            i+=3;
        }else if(numbers[i]=='s' && numbers[i+1]=='e'){
            bef+='7';
            i+=5;
        }else if(numbers[i]=='e'){
            bef+='8';
            i+=5;
        }
        else{
            bef+='9';
            i+=4;
        }
    }
    if(!bef.empty()) answer=stol(bef);
    return answer;
}