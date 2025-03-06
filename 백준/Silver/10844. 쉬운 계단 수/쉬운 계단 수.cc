#include <bits/stdc++.h>
using namespace std;

int n;
long long d[105][10];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;

  long long mod = 1000000000;
  for(int i=1; i<10; i++)
  d[1][i]=1;

  for(int i=2; i<=n; i++){
    d[i][0]=d[i-1][1]%mod;
    d[i][9]=d[i-1][8]%mod;
    for(int j=1; j<=8; j++){
      d[i][j]=(d[i-1][j-1]+d[i-1][j+1])%mod;
    }
  }
  long long ans=0;
  for(int i=0; i<10; i++)
  ans=(ans+d[n][i])%mod;

  cout<<ans;
}