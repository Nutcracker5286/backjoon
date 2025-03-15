#include <bits/stdc++.h>
using namespace std;

int n;
int d[1005][10];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;

  for(int i=0; i<10; i++)
  d[1][i]=1;


  int mod=10007;
  for(int i=2; i<=n; i++){
    for(int j=0; j<10; j++){
      int tmp=0;
      for(int k=0; k<=j; k++){
        tmp=(tmp+d[i-1][k])%mod;
      }
      d[i][j]=tmp;
    }
  }


  int ans=0;
  for(int i=0; i<10; i++)
  ans=(ans+d[n][i])%mod;
  cout<<ans;

}