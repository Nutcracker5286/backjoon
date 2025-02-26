#include <bits/stdc++.h>
using namespace std;

int n,m;

int d[100005];
int s[100005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m;

  for(int i=1; i<=n; i++)
  cin>>s[i];

  d[1]=s[1];
  for(int i=2; i<=n; i++){
    d[i]=d[i-1]+s[i];
  }

  while(m--){
    int i,j;
    cin>>i>>j;
    cout<<d[j]-d[i-1]<<"\n";
  }
}