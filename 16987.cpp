#include <bits/stdc++.h>
using namespace std;
#define D first
#define W second

/*
가장 왼쪽부터
왼쪽 계란과 무작위 선택
집은 계란이 깨지거나, 깰 수 있는 계란이 없을때 충돌 x
충돌
위 조건 만족 시 까지 반복
집은 계란이 가장 오른쪽에 있는 경우 종료
*/

int n,cnt, ans;
vector <pair <int, int>> egg;
bool egg_C[10];

int crash(pair <int, int> &egg1,pair <int, int> &egg2){
    egg1.D-=egg2.W;
    egg2.D-=egg1.W;
    int d1=egg1.D;
    int d2=egg2.D;
    //손에 들고 있는 계란이 깨진 경우
    if(d1<=0 && d2<=0) return -1;
    if(d1<=0) return 0;
    //손계란 안깨짐
    if(d2<=0) return 1;
    // 다 안깨짐
    return 2;
}


void solve(int t,vector<pair<int, int>> bef){
    if(t==n){
        ans=max(ans, cnt);
        return;
    }

    for (int i = t+1; i < egg.size(); i++)
    {
        if(egg_C[i]) continue;
        if(egg_C[t]) solve(t+1,bef);
        auto tmp=bef;
        int r=crash(tmp[t],tmp[i]);
        if(r==-1){ // 둘다 깨짐
            cnt+=2;
            egg_C[t]=egg_C[i]=1;
            solve(t+1, tmp);
            egg_C[t]=egg_C[i]=0;
            cnt-=2;
        }
        else if(r==0){ // 손계란 깨짐
            cnt++;
            egg_C[t]=1;
            solve(t+1, tmp);
            egg_C[t]=0;
            cnt--;
        }
        else if(r==1){ //손계란만 안깨짐
            cnt++;
            egg_C[i]=1;
            solve(t,tmp);
            egg_C[i]=0;
            cnt--;
        }
        else{//둘다 안깨짐
            solve(t,tmp);
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for (int i = 0; i < n; i++)
    {   int d; int w;
        cin>>d>>w; egg.push_back({d,w});
    }
    solve(0, egg);
    cout<<ans;
    
}