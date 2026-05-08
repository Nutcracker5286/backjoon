#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string>  sounds = {"aya", "ye", "woo", "ma"};
    
    for(auto ori : babbling){
        int idx= 0;
        bool possible = false;
        while(idx<ori.size()){
            bool ispass=false;
            for(auto sou : sounds){
                if(ori.substr(idx,sou.size()) == sou){
                    idx+=sou.size();
                    ispass=true;
                    break;
                }
            }
            if(!ispass){//옹알이가 안되면
                possible =false;
                break;
            }
            possible =1;
        }
        if(possible) answer++;
        
    }
    return answer;
}