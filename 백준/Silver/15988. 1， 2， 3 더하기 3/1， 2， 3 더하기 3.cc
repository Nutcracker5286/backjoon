#include <bits/stdc++.h>
using namespace std;

int t;
int n;
long long d[1000005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  long long mod = 1000000009;

  d[1]=1;
  d[2]=2;
  d[3]=4;

  for(int i=4; i<=1000000; i++){
    d[i]=(d[i-1]+d[i-2]+d[i-3])%mod;
  }
  while (t--)
  {
    cin>>n;
    cout<<d[n]<<'\n';
  }
  
}