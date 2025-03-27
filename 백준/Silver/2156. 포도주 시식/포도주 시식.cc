#include <bits/stdc++.h>
using namespace std;


int a[10005];
int d[10005][3];
int n;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=1; i<=n; i++)
  cin>>a[i];

  d[1][1]=a[1];
  d[2][1]=a[2];
  d[2][2]=a[2]+a[1];
  for(int i=3; i<=n; i++){
    int mx=0;
    for(int j=1; j<=i-2; j++)
      mx=max({d[j][1],d[j][2],mx});

    d[i][1]=mx+a[i];
    d[i][2]=d[i-1][1]+a[i];

   
  }

  int ans=d[1][1]; 
  for(int j=1; j<=n; j++)
    ans=max({d[j][1],d[j][2],ans});
    cout<<ans;
}