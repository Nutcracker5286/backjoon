#include <string>
#include <bits/stdc++.h>

using namespace std;

vector<string> user;
vector<string> ban;
set<set<int>> ishave;
vector<int> vis;
int ans;

bool isban(string &ori, string &b){
    if(ori.size() !=b.size()) return false;
    for(int i=0; i<b.size(); i++){
        if(b[i]=='*') continue;
        
        if(ori[i]!=b[i]){
            return false;
        }
    }
    
    return true;
}



/*
k+1을 선택하는 함수
벤 아이디만큼 선택하면 종료
    셋에 선택한 인덱스들을 담은 셋을 삽입

유저 아이디 중에서 선택하지 않고 문자열 부합하는것 선택
*/
void solve(int k){
    if(k == ban.size()){
        set<int> tmp;
        for(int i=0; i<vis.size(); i++)
            if(vis[i]) tmp.insert(i);
        ishave.insert(tmp);
        ans++;
        return ;
    }
    
    
    //유저 아이디 선택
    for(int i=0; i<user.size(); i++){
        if(vis[i]) continue;
        
        //현재 벤 아이디와 맞는지 체크
        if(!isban(user[i],ban[k])) continue;
        vis[i]=1;
        solve(k+1);
        vis[i]=0;
        
        
    }
    
}



/*
해당 밴 아이디별로  집합 설정
입력이 작아서 백트래킹을 이용한 조합 진행
*/
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    user =user_id;
    ban = banned_id;
    vis.assign(user_id.size(),0);
   
    solve(0);
    
    
    
    return ishave.size();
}