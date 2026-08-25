#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

/*
투포인터 , 슬라이딩 윈도우

전체 종류는 셋으로 카운팅
탐색 종류는 map으로 카운팅
    단 0이 되면 erase 시행

왼쪽에서부터 탐색
    조건 만족시
        최소 구간 갱신
    왼쪽 제거후 erase 시행 여부 결정
*/
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    set<string> ori (gems.begin(), gems.end());
    map<string, int> brt;
    int n  = gems.size();
    int en =0;
    
    int bl=0, br=n-1;
    for(int st = 0 ; st<n; st++ ){
        while(en < n &&  ori.size() > brt.size()){ //만족할때 까지 탐색
            brt[gems[en++]]++;
        }
        
        if(brt.size() == ori.size()){ // 만족시 갱신
            if(en-1 - st < br -bl){
                br = en-1;
                bl = st;
            }
        }
        
        
        //왼쪽 제거
        brt[gems[st]]--;
        if(brt[gems[st]]==0)
            brt.erase(gems[st]);
    }
    
    
    
    
    
    answer.push_back(bl+1);
    answer.push_back(br+1);
    return answer;
}