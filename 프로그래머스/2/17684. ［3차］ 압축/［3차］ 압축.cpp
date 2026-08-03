#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


/*
사전 추가


메세지 탐색
점프횟수 설정
현재 문자열 저장

반복
다음 문자열을 더한 임시 문자열 생성
맵에 있으면
    점프 횟수 증가
없으면
    정답에 현재 문자열의 맵값을 추가
    맵에 임시 문자열 삽입
    점프횟수만큼 증가
    다음 단계의 탐색

*/
vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> map;
    
    for(int i=0; i<26; i++){
        map[string(1,'A'+i)] = i+1;
    }
    
    int startNum=27;
    
    for(int i=0; i<msg.size(); i++){
        string cur = string(1, msg[i]);
        int jcnt = 1;
        
        bool isp=0;
        
        while(1){
            string tmp = cur + msg[i+jcnt];
            if(map.find(tmp) != map.end()){// 다음 문자열 존재시
                
                
            jcnt++;
                cur = tmp;
                if(i+jcnt >=msg.size()){isp=1; break;} 
                continue;
            }
            else{ // 새문자열 등록
               
                answer.push_back(map[cur]);
                map[tmp] = startNum++;
                break;
            }
                
        }
        if(isp){
            answer.push_back(map[cur]);
        }
        i+=cur.size()-1;
        
        
    }
    
    
    
    
    
    return answer;
}