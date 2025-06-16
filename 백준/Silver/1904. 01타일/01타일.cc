#include <bits/stdc++.h>
using namespace std;

int n;
int d[1000005][2];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin>>n;

  d[1][1]=1; d[2][1]=1; d[2][0]=1;

  int mod = 15746;
  for(int i=3; i<=n; i++){
    d[i][1]=(d[i-1][0]+d[i-1][1])%mod;
    d[i][0]=(d[i-2][1]+d[i-2][0])%mod;
  }
  cout<<(d[n][0]+d[n][1])%mod;
}