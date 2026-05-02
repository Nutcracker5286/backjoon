#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pt = {
    {1,2,3,4,5},
    {2,1,2,3,2,4,2,5}
    ,{3,3,1,1,2,2,4,4,5,5}
    
};
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(3,0);
    
    for(int i=0; i<answers.size(); i++){
        for(int j=0; j<3; j++){
            score[j] += pt[j][i%pt[j].size()] == answers[i];
        }
        
    }
    int maxS = *max_element(score.begin(),score.end());
    for(int i=0; i<3; i++){
        if(maxS == score[i]) answer.push_back(i+1);
    }
    
    return answer;
}