#include <bits/stdc++.h>
using namespace std;


int n,k;
int a[105];
int d[10005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>k;

  for(int i=1; i<=n; i++){
    cin>>a[i];
  }

  d[0]=1;
  for(int i=1; i<=n; i++){
    for(int j=a[i]; j<=k; j++){
      d[j]=d[j]+d[j-a[i]];
    }
  }
  cout<<d[k];
}