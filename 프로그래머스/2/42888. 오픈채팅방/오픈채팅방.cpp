#include <string>
#include <bits/stdc++.h>

using namespace std;





/*
닉네임 변경
    채팅방을 나간후, 새로운 닉네임으로 다시 들어옴
    채팅방에서 닉네임 변경
    
변경시 기존 출력도 변경

변경이나 마지막 들어온 사람 기준으로 출력

동작, 아이디, 이름

레코드를 순서대로 탐색
해당 아이디의 값이 있다면 현재 이름으로 변경
없어도 현재 이름으로 변경

변경 명령이면, 맵의 저장값 변경

    


*/
vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, pair<string,string>> rem ;//아이디, 닉네임,명령
    
    for(auto cmd : record){
        stringstream ss(cmd);
        string tr, id, name;
        ss>>tr>>id>>name;
        //변경이면
        if(tr == "Change"){
            rem[id] = {name,tr};
        }
        //나간기록이 있고, 현재 명령이 들어오는 경우
        else if (rem.find(id) != rem.end() && rem[id].second == "Leave" &&
                tr == "Enter"
                ){
            rem[id] = {name,tr};
            rem.erase(rem.find(id));
        }
        else if (tr == "Enter")             rem[id] = {name,tr};

    }
    
    for(auto cmd : record){
        stringstream ss(cmd);
        string tr, id, name;
        ss>>tr>>id>>name;
        
        //change면 패스
        if(tr=="Change") continue;
        
        
        //들어오는 경우
        else if(tr=="Enter"){
            string ori  = rem[id].first+"님이 들어왔습니다.";
            answer.push_back(ori);
        }
        
        //나가는경우
        else{
            string ori  = rem[id].first+"님이 나갔습니다.";
            answer.push_back(ori);
        }
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    return answer;
}