#include <bits/stdc++.h>
using namespace std;

int dp[20];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin>>t;
  dp[1]=1; dp[2]=2; dp[3]=4;
  for(int i=4; i<12; i++){
    dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
  }

  while(t--){
    int n;
    cin>>n;
    cout<<dp[n]<<'\n';
  }
}