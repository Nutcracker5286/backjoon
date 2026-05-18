#include <string>
#include <bits/stdc++.h>

using namespace std;
/*
케시 사이즈 만큼 캐시 생성
시티 탐색 시 존재하는지 확인, 존재하면 최근에 호출된것으로 앞으로 이동

*/
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> cacheList;
    unordered_map <string, list<string>::iterator> cacheMap;
    
    if(cacheSize==0){
        return cities.size()*5;
    }
    for(auto &word : cities){
        for(auto &c : word){
            c=tolower(c);
        }
    }
    
    for(auto c : cities){
        // hit
        if(cacheMap.count(c) == 1){
            answer+=1;
            
            //기존 위치에서 삭제후 제일 앞에 삽입, map 정보 갱신
            cacheList.erase(cacheMap[c]);
            cacheList.push_front(c);
            cacheMap[c]=cacheList.begin();
                   
        }
        else{ // miss
            cacheList.push_front(c);
            cacheMap[c] = cacheList.begin();
            
            // 사이즈 넘는지 확인하고 넘으면 삭제 처리
            if(cacheMap.size()>cacheSize){
                string del = cacheList.back();
                cacheList.pop_back();
                cacheMap.erase(del);
            }
            
            answer+=5;
        }
    }
    return answer;
}