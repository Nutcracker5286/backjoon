#include <bits/stdc++.h>
using namespace std;

int n;
int d[1005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;

  for(int i=1; i<=n; i++){
    cin>>d[i];
  }

  for(int i=2; i<=n; i++){
    for(int j=1; j<i; j++){
      d[i]=max(d[i],d[i-j]+d[j]);
    }
  }

  cout<<d[n];
}