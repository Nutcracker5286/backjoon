#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;

ll d[45];
vector<ll> vip={0};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m;

  for(int i=1; i<=m; ++i){
    int tmp;
    cin>>tmp;
    vip.push_back(tmp);
  }

  vip.push_back(n+1);

  d[0] = 1;  // 빈 자리가 없는 경우
  d[1]=1; 
  d[2]=2;

  for(int i=3; i<=n; i++){
    d[i]=d[i-1]+d[i-2];
  }

  int ans=1;
  for (int i = 1; i < vip.size(); i++) 
    ans *= d[vip[i] - vip[i - 1] - 1];
  cout<<ans;
}