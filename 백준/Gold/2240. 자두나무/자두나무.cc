#include <bits/stdc++.h>
using namespace std;

int t,w;
int a[1005];
int d[1005][3][35];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>t>>w;

  for(int i=1; i<=t; i++)
  cin>>a[i];

  a[1]==1?d[1][1][0]=1:d[1][2][1]=1;

  for(int i=2; i<=t; i++){
    for(int k=0; k<=w; k++){
      if(k> i ) continue;
      if(a[i]==1){
        d[i][1][k]=max(d[i-1][1][k],d[i-1][2][k-1])+1;
        d[i][2][k]=max(d[i-1][1][k-1],d[i-1][2][k]);
      }
      else{
        d[i][1][k]=max(d[i-1][1][k],d[i-1][2][k-1]);
        d[i][2][k]=max(d[i-1][1][k-1],d[i-1][2][k])+1;
      }
    }
  }

  int ans=0;
  for(int i=1; i<=2; i++){
    for(int k=0; k<=w; k++){
      ans=max(ans,d[t][i][k]);
    }
  }

  cout<<ans;
}