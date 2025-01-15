#include <bits/stdc++.h>
using namespace std;

int n,ans;
// (내구도, 무게)
pair<int, int> egg[10];
// 깨졌는지
bool isBroken[10];

bool isAllBroken(int h){
    for(int i=0; i<n; i++){
        if(i==h) continue;
        if(!isBroken[i]) return false;
    }
    return true;
}

void update(int h, int i){
    egg[h].first-=egg[i].second;
    egg[i].first-=egg[h].second;
    if(egg[h].first<=0) isBroken[h]=true;
    if(egg[i].first<=0) isBroken[i]=true;

}

void unDo(int h, int i){
    egg[h].first+=egg[i].second;
    egg[i].first+=egg[h].second;
    if(egg[h].first>0) isBroken[h]=false;
    if(egg[i].first>0) isBroken[i]=false;

}

void solve(int k){
    if(k==n){
        int cnt=0;
        for(int i=0; i<n; i++)
        cnt+=isBroken[i]==1;
        ans=max(ans,cnt);
        return;
    }
    // 손에 든 에그 || 다른거 모두 깨졌으면
    if(isBroken[k] || isAllBroken(k)){
        solve(k+1);
        return;
    }
    
    for(int i=0; i<n; i++){
        // 깨고 싶은 에그
        if(isBroken[i]) continue;
        if(k==i) continue;

        update(k,i);
        solve(k+1);
        unDo(k,i);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;

    for(int i=0; i<n; i++)
    cin>>egg[i].first>>egg[i].second;
    solve(0);
    cout<<ans;
}