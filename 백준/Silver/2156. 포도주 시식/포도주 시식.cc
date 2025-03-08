#include <bits/stdc++.h>
using namespace std;

int n;
long d[10005][3];
long a[10005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;

  for(int i=1; i<=n; ++i)
  cin>>a[i];

  d[1][1]=a[1];
  d[2][1]=a[2];
  d[2][2]=a[1]+a[2];
  for(int i=3; i<=n ; ++i){
    long mx=0;
    for(int j=1; j<=i-2; ++j){
      for(int k=1; k<=2; k++){
        mx=max(mx,d[j][k]);
      }
    }
    d[i][1]=mx+a[i];
    d[i][2]=d[i-1][1]+a[i];
  }

  long ans=d[1][1];
  for(int j=2; j<=n; ++j){
    for(int k=1; k<=2; k++){
      ans=max(ans,d[j][k]);
    }
  }
  cout<<ans;
}