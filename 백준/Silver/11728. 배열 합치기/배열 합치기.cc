#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1000010], b[1000010],c[2000010];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m;

  for(int i=0; i<n; i++)
  cin>>a[i];

  for(int i=0; i<m; i++)
  cin>>b[i];

  int aIdx=0;
  int bIdx=0;

  for(int i=0; i<n+m; i++){
    if(aIdx==n) c[i]=b[bIdx++];
    else if(bIdx==m) c[i]=a[aIdx++];
    else if(a[aIdx]<b[bIdx]) c[i]=a[aIdx++];
    else c[i]=b[bIdx++];
  }

  for(int i=0; i<n+m; i++)
  cout<<c[i]<<' ';
}