#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int toMin(const string &s){
    return stoi( s.substr(0,2)) * 60 + stoi(s.substr(3));
}

string toTime(int time){
    string h = to_string(time /60);
    string m = to_string(time%60);
    
    if(h.size()==1) h = "0"+h;
    if(m.size()==1) m= "0"+m;
    return h+":"+m;
}



/*
마지막 셔틀의 탑승자를 기준
탑승자가 m명 미만이면
    마지막 셔틀의 시간이 정답
아니면
    마지막셔틀의 탑승자 중 마지막 탑승자보다 1분 빠름

크루원 탑승 시간을 분으로 전환
탑승 전환 후
    마지막 셔틀 확인

*/
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> crew ;
    for(string s : timetable)
        crew.push_back(toMin(s));
    
    
    sort(crew.begin(),crew.end());
    
    
    //n번의 시행횟수 체크
    int idx =0; //미탑승 크루중 제일 앞 순번
    for(int i=0; i<n; i++){
        int cur  = toMin("09:00") + t*i;
        
        int cnt =0;
        //현재 셔틀 시간보다 작고, m명 이하면 탑승
        while(idx<timetable.size() && crew[idx] <= cur &&
             cnt <m
             ){
            idx++;
            cnt++;
        }
        
        // 마지막 셔틀
        if(i==n-1){
            //셔틀이 널널
            if(cnt < m){
                return toTime(cur);
            }
            //차 있으면
            return toTime(crew[idx-1]-1);
        }
    }
    
    
    
    
    
    return answer;
}