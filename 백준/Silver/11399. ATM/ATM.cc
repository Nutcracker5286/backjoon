#include <bits/stdc++.h>
using namespace std;

int n;
int p[1005];
int t[1005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=0; i<n; i++){
    cin>>t[i];
    p[i]=t[i];
  }

  sort(t,t+n);

  int ans=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<i; j++){
      p[i]=t[j]+p[i];
    }
    ans+=p[i];
  }

  cout<<ans;
}