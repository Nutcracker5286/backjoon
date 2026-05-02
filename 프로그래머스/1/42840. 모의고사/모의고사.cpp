#include <bits/stdc++.h>

/*
특정 패턴이 정해진 사람 3명, 정답 배열이 주어짐
각 인원수가 맞힌 정답 수 구하기
정답 수 기준으로 순위 매기기, 동차인원이 있으면 번호대로 오름차순
페어 정답, 번호
*/


using namespace std;
vector<pair<int,int>> rk(3); // 정답수, 번호



vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> ps[3];
    
    // 답안 작성
    for(int i= 0; i<answers.size(); i++){
    //1번
        ps[0].push_back(i%5+1);
    //2번, 주기가 8이고 홀수에는 2 삽입 나머지는 1,3,4,5 (1,3,5,7 나머지)
        if(i%2==0) ps[1].push_back(2);
        else{
            if(i%8==1)  ps[1].push_back(1);
            if(i%8==3)  ps[1].push_back(3);
            if(i%8==5)  ps[1].push_back(4);
            if(i%8==7)  ps[1].push_back(5);
        }
    //3번, 주기 10, 나머지 01 ,23, 45,67,89
        //              33  11 22 44 55 삽입
        int res = i%10;
        if(res>=0 && res<=1){
            ps[2].push_back(3); 
        }
        else if(res>=2 && res<=3){
            ps[2].push_back(1);
        }
        else if(res>=4 && res<=5){
            ps[2].push_back(2); 
        }
        else if(res>=6 && res<=7){
            ps[2].push_back(4); 
        }
        else{
            ps[2].push_back(5);
        }
        
        // 채점
        for(int j=0; j<3; j++){
            rk[j].first +=  ps[j][i]==answers[i];
            rk[j].second = j;
        }
    }
    
    //개수 내림차, 번호 오름차
    sort(rk.begin(),rk.end(), [](auto &a, auto &b){
        if(a.first == b.first){
            return  a.second < b.second;
        }
            return a.first> b.first;
    });
    
    int Mscore = rk[0].first;
    for(auto [sc, id] : rk){
        if(sc == Mscore) answer.push_back(id+1);
    }
    
    
    for(auto [c1,c2] : rk)
    cout<<c1<<' '<<c2<<'\n';
    return answer;
}