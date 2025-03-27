#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
ll d[45];
vector<ll> vip;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m;

  vip.push_back(0);
  for(int i=0; i<m; i++){
    ll t; cin>>t;
    vip.push_back(t);
  }
  vip.push_back(n+1);

  d[0]=1;
  d[1]=1; d[2]=2; d[3]=3;

  for(int i=4; i<=n; i++){
    d[i]=d[i-1]+d[i-2];
  }

  ll ans=1;
  for(int i=0; i<=m; i++){
   ans*=d[vip[i+1]-vip[i]-1];
  }
  cout<<ans;


}