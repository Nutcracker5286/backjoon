#include <string>
#include <vector>

using namespace std;
/*
스킬이 나오고, 스킬의 순서가 뒤집히면
    실패한 스킬트리
이외에는 가능한 스킬트리

초기 풀이는 트리에서 스킬의값을 체크하는식으로 진행 => 실패

트리상에서 스킬순서로 함께 확인하는 식으로 진행
*/
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(auto tree : skill_trees){
        // 성공적인 스킬트리인지 체크
        bool isp =1;
        
        //현재까지 나온 스킬트리의 인덱스
        int idx =0;
        
        for(auto e: tree){
            if(skill.find(e)==-1) continue; //스킬트리의 스킬이 정해진 스킬에 없는 경우 패스
            //현재까지 나온 스킬트리의 스킬이 정해진 순서에 맞는지 체크
            if(skill[idx] == e){
                idx++;
            }
            else{ //나와야 되는 스킬트리에 안맞음
                isp=0;
                break;
            }
        }
        
        
        if(isp) {
            answer++;
        }
    }
    
    
    return answer;
}